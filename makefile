run:t
	./t
	rm t
	
t:1.1.c
	gcc 1.1.c -o t -lpthread
