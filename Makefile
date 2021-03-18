FLAGS = -lm
GRAPHICS_LIB ?= src/graphics/

all:
	@make --no-print-directory linux
	@make --no-print-directory windows
windows:
	@make --no-print-directory windows32
	@make --no-print-directory windows64

linux: bin/test
windows32: bin/test32.exe
windows64: bin/test64.exe

# linux
bin/test: mk/game.o mk/engine.a
	gcc mk/game.o mk/engine.a $(FLAGS) -o bin/test

mk/game.o: test/game.c src/engine.h src/shared.h 
	gcc -c test/game.c -o mk/game.o

mk/engine.a: src/engine.c src/shared.h $(GRAPHICS_LIB) 
	gcc -c src/engine.c -o mk/engine.a


# windows 32bit
bin/test32.exe: mk/game32.obj  mk/engine32.obj
	i686-w64-mingw32-gcc mk/game32.obj mk/engine32.obj $(FLAGS) -o bin/test32.exe

mk/game32.obj: test/game.c src/engine.h src/shared.h
	i686-w64-mingw32-gcc -c test/game.c -o mk/game32.obj

mk/engine32.obj: src/engine.c src/shared.h $(GRAPHICS_LIB) 
	i686-w64-mingw32-gcc -c src/engine.c -o mk/engine32.obj


# windows 64bit
bin/test64.exe: mk/game64.obj  mk/engine64.obj
	x86_64-w64-mingw32-gcc mk/game64.obj mk/engine64.obj $(FLAGS) -o bin/test64.exe

mk/game64.obj: test/game.c src/engine.h src/shared.h
	x86_64-w64-mingw32-gcc -c test/game.c -o mk/game64.obj

mk/engine64.obj: src/engine.c src/shared.h $(GRAPHICS_LIB)
	x86_64-w64-mingw32-gcc -c src/engine.c -o mk/engine64.obj


clear:
	rm mk/*
	rm bin/*
