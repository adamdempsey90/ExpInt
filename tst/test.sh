#!/bin/bash


rm *.o
rm a.out
cp ../expint.c .

gcc -c -O3 expint.c -o expint.o
gcc -c -O3 test.c -o test.o

gcc expint.o test.o -lm 

./a.out
python3 test.py 
