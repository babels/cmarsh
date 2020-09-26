CC=x86_64-w64-mingw32-g++
STRIP=mingw-strip
MC=mcs
UED=

all:
	${CC} -c -Wall unt.c
	${CC} -shared -Wall -o unt.dll unt.o unt.h
	#${MC} -r:#{foo} -target:library -sdk:2 -out:libfoo.dll #{files}
	#${CC} -L`pwd` -Wall -o test.exe main.c -lfoo foo.h

	#${STRIP} -Xx *.{exe,dll,o}

clean:
	rm -f *.{ext,dll,o} > /dev/null 2>&1
