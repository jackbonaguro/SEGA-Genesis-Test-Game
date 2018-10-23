all:
	make build
	make emu

build:
	${GDK}/bin/make -f ${GDK}/makefile.gen

main.c:
	${GDK}/bin/make -f ${GDK}/makefile.gen src/main.c

fontTiles.s:
	${GDK}/bin/make -f ${GDK}/makefile.gen src/fontTiles.s

emu:
	${GDK}/mess64/mess64.exe genesis -cart out/rom.bin  -window -skip_gameinfo

gens:
	make build
	${GDK}/gens_kmod/gens.exe out/rom.bin

debug:
	${GDK}/mess64/mess64.exe genesis -cart out/rom.bin  -window -debug -skip_gameinfo