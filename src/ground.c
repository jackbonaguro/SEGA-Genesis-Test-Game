#include <genesis.h>

const u32 ground[9][8] = {
	0x000FFFFF, 0x00F000F0, 0x0F000F00, 0xF000F000, 0xFFFFFFFF, 0xF0F00000, 0xF00F0000, 0xF000F000, 	//  Tile: 0
	0xF0000F00, 0xF00000F0, 0xF000000F, 0xF0000000, 0xFF000000, 0xF0F00000, 0xF00F0000, 0xF000F000, 	//  Tile: 1
	0xF0000F00, 0xF00000F0, 0xF000000F, 0xFF000000, 0xF0F00000, 0x0F0F0000, 0x00F0F000, 0x000FFFFF, 	//  Tile: 2
	0xFFFFFFFF, 0x00F000F0, 0x0F000F00, 0xF000F000, 0xFFFFFFFF, 0x00F00000, 0x000F0000, 0x0000F000, 	//  Tile: 3
	0x00000F00, 0x000000F0, 0x0000000F, 0xF0000000, 0x0F000000, 0x00F00000, 0x000F0000, 0x0000F000, 	//  Tile: 4
	0x00000F00, 0x000000F0, 0x0000000F, 0xF0000000, 0x0F000000, 0x00F00000, 0x000F0000, 0xFFFFFFFF, 	//  Tile: 5
	0xFFFFF000, 0x00F00F00, 0x0F000FF0, 0xF000F00F, 0xFFFFFFFF, 0x00F0000F, 0x000F000F, 0x0000F00F, 	//  Tile: 6
	0x00000F0F, 0x000000FF, 0x0000000F, 0xF000000F, 0x0F00000F, 0x00F0000F, 0x000F000F, 0x0000F00F, 	//  Tile: 7
	0x00000F0F, 0x000000FF, 0x0000000F, 0xF000000F, 0x0F00000F, 0x00F0000F, 0x000F00F0, 0xFFFFFF00, 	//  Tile: 8
	};