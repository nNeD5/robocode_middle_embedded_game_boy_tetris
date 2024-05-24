#include "src/GameBoy/src/GameBoy.h"
#include "src/GameBoy/src/Blocks.h"

GameBoy gb;
const int blockWidth = 4;
const int blockHeight = 4;

int rot = 0;


void setup(void) {
	Serial.begin(9600);
	gb.begin(5);
	create_block(random(0, 7));
	draw_block(gb.block[rot], 5, 8);
}
void loop(void) {
}

void draw_block(byte block[4][4], int x, int y) {
	for(int i = 0; i < blockHeight; ++i) {
		for(int j = 0; j < blockWidth; ++j) {
			if (block[i][j]) {
				gb.drawPoint(x + i, y + j);
			}
		}
	}
}

void create_block(int num) {
	rot = random(0, 4);
	if (num == 0) gb.generateBlock(gb.block, Z_Block_1, Z_Block_2, Z_Block_3, Z_Block_4);
	if (num == 1) gb.generateBlock(gb.block, I_Block_1, I_Block_2, I_Block_3, I_Block_4);
	if (num == 2) gb.generateBlock(gb.block, J_Block_1, J_Block_2, J_Block_3, J_Block_4);
	if (num == 3) gb.generateBlock(gb.block, L_Block_1, L_Block_2, L_Block_3, L_Block_4);
	if (num == 4) gb.generateBlock(gb.block, O_Block_1, O_Block_2, O_Block_3, O_Block_4);
	if (num == 5) gb.generateBlock(gb.block, S_Block_1, S_Block_2, S_Block_3, S_Block_4);
	if (num == 6) gb.generateBlock(gb.block, T_Block_1, T_Block_2, T_Block_3, T_Block_4);
}
