main: main.cpp
	g++ -Wall -lcrypto -O2 main.cpp -o main

clean:
	$(RM) main
