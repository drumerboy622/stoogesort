make: stoogesort.c
	gcc -g -Wall -std=c99 -o stoogesort stoogesort.c
	./stoogesort

timefiles: stoogeTime.c
	gcc -g -Wall -std=c99 -o stoogeTime stoogeTime.c
	./stoogeTime

clean: 
	rm stooge.out stoogesort stoogeTime
	
