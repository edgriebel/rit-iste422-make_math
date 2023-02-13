ALL : test main
	@echo Build Complete!

# -f is "Force" option for 'rm' 
# rm will throw an error if the files you are renaming aren't there.
# We add -f to suppress the error. Also, rm won't remove files that
# are marked read-only unless the -f flag is supplied
clean : 
	rm -f *.o main tester

main : main.o libmath.o
	$(CC) -o main main.o libmath.o

%.o : %.c libmath.h
	$(CC) -c -g $<

# run with some examples
run : main
	@echo Lets try some examples!
	./main 10 x 20
	./main 10 '*' 20
	./main 10 + 20
	./main 10 / 20
	@echo Done!!

test : tester
	./tester
	@echo SUCCESS

tester : libmath.o tester.o
	$(CC) -o $@ $^

# .PHONY is a special target which tells `make` that
# it shoudn't check for a file matching the target
#
# You can verify what happens by commenting this out,
# running "touch ALL" and they running "make", you'll
# see that nothing gets executed.
.PHONY : clean ALL