#include <genesis.h>
#include <tiles.h>
#include <palettes.h>

s16 x, y;
u16 scale, offset;
s16 hscroll[224];

u16 nextTile, nextSprite;

u16 loadTile(const u32* address, int size) {
	u16 result = nextTile;
	for(int i = 0; i < size; i++) {
		VDP_loadTileData(address + (i * 8), nextTile, 1, CPU);
		nextTile++;
	}
	return result;
}

struct {
	int left;
	int right;
	int up;
	int down;
	int a;
} input;

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		if (state & BUTTON_LEFT)
			input.left = 1;
		else if (changed & BUTTON_LEFT)
			input.left = 0;
		
		if (state & BUTTON_RIGHT)
			input.right = 1;
		else if (changed & BUTTON_RIGHT)
			input.right = 0;
		
		if (state & BUTTON_UP)
			input.up = 1;
		else if (changed & BUTTON_UP)
			input.up = 0;
		
		if (state & BUTTON_DOWN)
			input.down = 1;
		else if (changed & BUTTON_DOWN)
			input.down = 0;
		
		if (state & BUTTON_A)
			input.a = 1;
		else if (changed & BUTTON_A)
			input.a = 0;
	}
}

int main()
{
	x = 0;
	y = 0;
	scale = 2;

	nextTile = 0;

	JOY_init();
	JOY_setEventHandler(&myJoyHandler);

	VDP_setPaletteColors(PAL1 * 16, (const u16*)&testPalette, 16);

	nextTile = 2;
	int playerIndex, groundIndex;
	playerIndex = loadTile((const u32*)frog, 4);

	groundIndex = loadTile((const u32*)ground, 9);
	for (int i = 0; i < 9; i++) {
		int fx = i / 3;
		int fy = i % 3;
		VDP_setTileMapXY(PLAN_A,
			TILE_ATTR_FULL(PAL2,0,0,0,groundIndex+i),
			20+fx,
			20+fy);
	}

	VDPSprite mySprite;
	
	s16 px, py;
	px = 8;
	py = 8;
	mySprite.size = SPRITE_SIZE(2,2);
	mySprite.attribut = TILE_ATTR_FULL(PAL1,1,0,0,playerIndex);
	mySprite.link  = 0;
	VDP_setSpriteFull(0, 
		x,
		y,
		mySprite.size,
		mySprite.attribut,
		mySprite.link);

	u16* hScrollTable = (u16*)VDP_getHScrollTableAddress();
	VDP_setScrollingMode(HSCROLL_LINE, VSCROLL_PLANE);

	char* text = "Hello World!";

	while(1)
	{
		if (input.left)
			x--;
		if (input.right)
			x++;
		if (input.up)
			y--;
		if (input.down)
			y++;
		px = x / scale;
		py = y / scale;

		sprintf(text, "X: %d, Y: %d", x, y);

		VDP_drawText(text,
			14,
			13);

		offset++;
		for(int i = 0; i < VDP_getScreenHeight(); i++) {
			hscroll[i] = sinFix16((offset) & 1023);
		}
		VDP_setHorizontalScrollLine(PLAN_A, 0, hscroll,
			VDP_getScreenHeight(), FALSE);

		VDP_setSpritePosition(0, px, py);		
		VDP_updateSprites(1, 1);

		//wait for screen refresh
		VDP_waitVSync();
	}
	return (0);
}