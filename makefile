all:	oss user

oss:	oss.c
	gcc -o oss oss.c

user:	user.c
	gcc -o user user.c

clean:
	rm -f oss user

