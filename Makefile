all : program

program : proba_do_pracowni_SO.cpp
	g++ -pthread -Wall -Wextra -Werror proba_do_pracowni_SO.cpp -o program
	
run :
	./program

