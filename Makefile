all:
	cd ./src && \
	gcc -o quad main.c input.c solve.c seatest.c -lm
test:
	cd ./src && \
	gcc -o quad main.c input.c solve.c seatest.c -lm; \
	./quad debug
clean:
	cd ./src && \
	rm quad
