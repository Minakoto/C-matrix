CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = s21_create_matrix.c s21_remove_matrix.c s21_matrix_calc.c s21_matrix_aux.c
OBJS = s21_create_matrix.o s21_remove_matrix.o s21_matrix_calc.o s21_matrix_aux.o

all: s21_matrix

s21_matrix: test.o $(OBJS)
	@$(CC) $(CFLAGS) test.o $(OBJS) -o test
	@rm *.o

test.o: test.c
	@$(CC) $(CFLAGS) -c test.c

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)


memchk: s21_matrix
	valgrind --tool=memcheck --leak-check=full ./test

clean:
	@rm *.o test

