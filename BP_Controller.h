#pragma once

enum {
	PAD_1,
	PAD_2
};

enum {
	PAD_UP = PADLup,
	PAD_DOWN = PADLdown,
	PAD_LEFT = PADLleft,
	PAD_RIGHT = PADLright,
	PAD_TRIANGLE = PADRup,
	PAD_CROSS = PADRdown,
	PAD_SQUAR = PADRleft,
	PAD_CIRCLE = PADRright,
	PAD_L1 = PADL1,
	PAD_R1 = PADL2,
	PAD_L2 = PADR1,
	PAD_R2 = PADR2,
	PAD_START = PADstart,
	PAD_SELECT = PADselect
};

char pad[2][34];

void padsInit() {
	PadInit(pad[0], pad[1], 17, 17);
}

void padsUpdate() {
	unsigned long padStatus = PadRead(0);
	unsigned short pad1Status = padStatus;
	unsigned short pad2Status = padStatus << 2;

	{
		unsigned int i = 0;
		while (i < 17) {
			pad[0][i] = pad[1][i] = false;
			i++;
		}
	}

	if (pad1Status & PAD_UP)
		pad[0][PAD_UP] = 1;
	if (pad1Status & PAD_DOWN)
		pad[0][PAD_DOWN] = 1;
	if (pad1Status & PAD_LEFT)
		pad[0][PAD_LEFT] = 1;
	if (pad1Status & PAD_RIGHT)
		pad[0][PAD_RIGHT] = 1;

	if (pad1Status & PAD_TRIANGLE)
		pad[0][PAD_TRIANGLE] = 1;
	if (pad1Status & PAD_CROSS)
		pad[0][PAD_CROSS] = 1;
	if (pad1Status & PAD_SQUAR)
		pad[0][PAD_SQUAR] = 1;
	if (pad1Status & PAD_CIRCLE)
		pad[0][PAD_CIRCLE] = 1;
}