all:	oss user

oss:	oss.c
	gcc -o oss oss.c

worker:	user.c
	gcc -o user user.c

clean:
	rm -f oss user
