run:t
	./t
	rm t
	
t:test_1_1.c
	gcc test_1_1.c -o t -lpthread
