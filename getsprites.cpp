#include <windows.h> 
#include <d2d1.h>
#include "mapfunctions.h"
// #include <stdio.h>
#pragma comment(lib, "d2d1.lib")
// int stonemap[] = {1,2,3,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,22,26,27,28,29,30,31,32,33,34,35,42,43,44,45,46,47,48,49,50,58,59,60,61,62,63,64,65,75,76,77,78,79,80,97,98,111,112,113,114,127,128,129,130,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176};
// int cavemap[] = {21};
int greensprite[16][16] = {
    {1,1,1,2,0,2,2,0,1,1,2,2,0,2,1,1},
    {1,1,1,1,2,2,0,1,1,1,1,1,2,2,2,0},
    {1,1,1,1,2,2,0,1,1,1,1,1,2,2,1,2},
    {0,1,1,1,2,2,0,1,1,1,1,1,1,2,1,2},
    {0,1,1,1,2,2,0,1,1,1,1,1,1,2,1,2},
    {1,1,1,1,2,0,1,1,1,1,1,1,1,1,1,2},
    {1,1,1,1,2,0,1,1,1,1,1,0,0,2,2,0},
    {1,1,1,1,2,0,1,1,1,1,0,1,1,1,2,0},
    {1,1,1,2,2,0,1,1,1,1,0,1,1,1,1,2},
    {1,1,1,2,2,0,1,1,1,1,0,1,1,1,1,2},
    {0,1,2,2,2,0,2,1,1,2,0,1,1,1,2,2},
    {0,1,2,0,0,0,2,2,1,2,0,1,1,1,2,0},
    {1,2,0,1,1,1,1,1,2,2,0,1,1,1,2,0},
    {1,2,0,1,1,1,1,2,2,2,0,1,1,1,2,0},
    {1,0,1,1,1,1,1,1,2,2,2,1,1,2,2,2},
    {2,0,1,0,1,1,0,2,0,2,2,0,0,2,2,0}
};
int cavesprite[16][16]={
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2} 
};
int bushsprite[16][16]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,1,2,2,2,0,0,0,0,0,0},
    {0,0,1,0,1,1,1,1,1,2,2,2,2,0,0,0},
    {0,0,1,1,2,1,1,1,1,1,2,2,1,2,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,2,2,2,0,0},
    {0,1,1,1,1,1,2,1,1,1,2,1,2,2,2,0},
    {1,1,1,1,1,1,1,1,1,1,2,2,2,2,0,0},
    {1,1,2,1,1,1,1,1,1,1,1,2,2,2,2,0},
    {0,1,1,1,1,1,1,1,2,1,1,2,2,1,2,0},
    {1,1,1,1,2,1,1,1,1,1,1,2,2,2,2,0},
    {1,1,1,1,1,1,1,1,1,2,2,2,2,2,0,0},
    {1,1,2,1,1,1,1,1,1,1,2,1,2,2,0,0},
    {0,1,1,1,1,1,1,2,2,2,2,2,2,0,0,0},
    {0,0,0,1,1,3,1,3,2,2,1,0,0,0,0,0},
    {0,0,0,0,2,3,3,3,3,3,2,2,2,2,2,2},
    {0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0}
};
int watersprite[16][16]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,2,1,1,1,1,1,1,1,2,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,2,1,1,1,1,1,1,1,2,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,2,1,1,1,1,1,1,1,2,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int uptree[16][16] = {
    {0,0,0,0,0,0,0,0,0,0,1,1,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,1,2,2,0},
    {0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2},
    {0,0,0,0,0,0,2,2,0,1,1,1,1,1,2,2},
    {0,0,0,0,0,0,1,2,0,1,1,1,1,2,2,2},
    {0,0,0,0,0,1,1,2,0,1,1,1,1,1,2,2},
    {0,0,0,0,0,1,1,2,2,1,1,1,1,1,2,0},
    {0,0,0,2,2,1,1,2,1,1,1,1,1,1,1,0},
    {0,0,1,1,2,1,1,2,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,2,1,1,1,1,1,1,2,0},
    {0,1,1,1,1,1,1,2,0,1,1,1,1,1,2,2},
    {0,1,1,1,2,1,2,2,2,1,1,1,1,1,2,2},
    {0,1,1,1,2,1,2,2,1,1,1,1,1,1,2,2},
    {1,1,1,1,1,1,2,2,2,1,1,1,1,2,2,0},
    {1,1,1,1,1,1,2,2,2,1,2,2,1,1,2,0}
};
int flattree[16][16] = {
    {0,0,1,1,2,2,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,2,2,0,0,0,0,1,2,0,0,0},
    {1,1,1,1,1,1,2,0,0,0,1,1,1,2,0,0},
    {0,1,1,1,1,1,2,2,0,1,1,1,1,1,2,0},
    {0,1,1,1,1,1,2,2,2,1,1,1,1,1,2,0},
    {0,1,1,1,1,2,2,2,0,1,1,1,1,1,1,2},
    {0,1,1,1,1,1,2,2,0,1,1,1,1,1,1,2},
    {2,1,1,1,1,1,2,0,0,1,1,1,1,1,2,2},
    {1,1,1,1,1,1,1,0,1,1,1,1,1,1,2,0},
    {1,1,1,1,1,1,1,0,1,1,1,1,1,2,2,0},
    {1,1,1,1,1,1,2,0,1,1,1,1,1,2,2,0},
    {0,1,1,1,1,1,2,2,0,1,1,1,1,1,2,2},
    {2,1,1,1,1,1,2,2,2,1,1,1,1,1,1,2},
    {1,1,1,1,1,1,2,2,0,0,2,2,1,1,1,2},
    {2,1,1,1,1,2,2,0,1,1,1,1,2,1,2,2},
    {2,1,2,2,1,1,2,0,1,1,1,2,2,1,1,2}
};
int downtree[16][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,2,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0},
    {2,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,2,1,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,2,2,1,1,2,2,2,0,0,0},
    {1,1,1,1,1,1,2,0,1,2,1,1,1,2,0,0},
    {1,1,1,1,1,2,2,0,1,1,1,1,1,2,0,0},
    {1,1,1,1,1,2,2,0,1,1,1,1,1,1,2,0},
    {0,1,1,1,1,1,2,2,0,1,1,1,1,1,2,0},
    {2,1,1,1,1,1,1,2,0,1,1,1,1,1,2,0},
    {0,0,2,2,1,1,1,2,0,1,1,1,1,2,2,0},
    {1,1,1,1,2,1,2,2,0,2,2,1,1,2,2,0},
    {1,1,1,2,2,1,1,2,0,2,2,2,1,2,0,0}
};
int stonedown[16][16] = {
    {1,1,1,1,0,1,1,1,2,2,2,0,1,1,2,2},
    {1,1,1,1,1,1,1,1,1,1,2,0,1,1,1,2},
    {1,1,1,2,1,1,1,1,1,1,2,0,1,1,1,2},
    {1,1,1,2,1,1,1,1,1,1,2,0,1,1,1,1},
    {1,1,1,2,1,1,1,1,1,1,2,0,1,1,1,1},
    {1,1,1,2,1,1,1,1,1,1,2,0,1,1,1,1},
    {2,1,2,2,1,1,1,1,1,1,2,2,0,1,1,1},
    {0,2,2,2,0,1,1,1,1,1,2,2,2,0,1,1},
    {0,0,0,2,2,1,1,1,1,1,2,2,2,0,1,1},
    {0,0,0,0,2,1,2,1,1,2,2,2,2,0,1,1},
    {0,0,0,0,0,2,2,2,2,2,2,2,2,0,1,1},
    {0,0,0,0,0,0,0,0,2,2,2,2,2,0,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2}
};
int stoneup[16][16] = {
    {0,1,1,1,1,1,1,2,2,2,0,1,1,2,2,2},
    {0,1,1,1,1,1,1,1,2,2,0,1,1,1,2,2},
    {0,1,2,2,1,1,1,1,2,2,0,1,1,1,2,2},
    {0,0,1,1,2,1,1,1,2,2,0,1,1,1,2,0},
    {0,1,1,1,2,1,1,1,2,2,0,1,1,1,2,0},
    {0,1,1,1,2,1,1,1,2,2,0,1,2,2,0,0},
    {0,1,1,1,2,1,1,1,2,2,2,2,0,0,0,0},
    {0,1,1,1,2,1,1,1,2,2,0,0,0,0,0,0},
    {0,1,1,1,2,1,1,2,2,0,0,0,0,0,0,0},
    {0,1,1,1,2,1,1,2,2,0,0,0,0,0,0,0},
    {2,0,1,1,2,1,1,2,2,0,0,0,0,0,0,0},
    {2,0,1,1,2,1,1,2,2,0,0,0,0,0,0,0},
    {2,0,1,1,2,1,2,2,0,0,0,0,0,0,0,0},
    {2,0,1,2,2,2,2,0,0,0,0,0,0,0,0,0},
    {2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int linkSpriteup[16][16] = {
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,2,0,1,1,1,1,1,1,1,1,0,2,0,0},
    {0,0,2,1,1,1,1,1,1,1,1,1,1,2,0,0},
    {0,0,2,3,1,1,1,1,1,1,1,1,3,2,0,0},
    {0,0,2,2,3,3,1,1,1,1,3,3,2,2,0,0},
    {0,0,0,2,3,3,3,1,1,3,3,3,2,0,0,0},
    {0,0,0,3,1,3,3,3,3,3,3,1,3,0,0,0},
    {0,0,0,3,3,1,1,1,1,1,1,1,3,3,0,0},
    {0,0,2,3,3,1,1,1,1,1,1,1,3,3,0,0},
    {0,0,2,3,3,1,1,1,1,1,1,3,3,0,0,0},
    {0,0,2,2,1,3,3,3,3,3,3,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,3,1,1,1,1,1,3,3,3,0,0,0},
    {0,0,0,0,0,3,3,0,0,3,3,3,3,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0}
};
int linkSpriteupmoving[16][16] = {
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,2,0,1,1,1,1,1,1,1,1,0,2,0,0},
    {0,0,2,1,1,1,1,1,1,1,1,1,1,2,0,0},
    {0,0,2,3,1,1,1,1,1,1,1,1,3,2,0,0},
    {0,0,2,2,3,3,1,1,1,1,3,3,2,2,0,0},
    {0,0,0,2,3,3,3,1,1,3,3,3,2,0,0,0},
    {0,0,0,3,1,3,3,3,3,3,3,1,3,0,0,0},
    {0,0,3,3,1,1,1,1,1,1,1,3,3,0,0,0},
    {0,0,3,3,1,1,1,1,1,1,1,3,3,2,0,0},
    {0,0,0,3,3,1,1,1,1,1,1,3,3,2,0,0},
    {0,0,0,1,1,3,3,3,3,3,3,1,2,2,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,3,3,3,1,1,1,1,1,3,0,0,0,0},
    {0,0,0,3,3,3,3,0,0,3,3,0,0,0,0,0},
    {0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0}
};

int linkSpritedown[16][16] = {
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,2,0,1,3,3,3,3,3,3,1,0,2,0,0},
    {0,0,2,0,3,3,3,3,3,3,3,3,0,2,0,0},
    {0,0,2,2,3,2,1,2,2,1,2,3,2,2,0,0},
    {0,0,2,2,3,2,3,2,2,3,2,3,2,2,0,0},
    {0,0,0,2,2,2,2,2,2,2,2,2,2,3,0,0},
    {0,0,0,1,1,2,2,3,3,2,2,1,1,3,0,0},
    {0,3,3,3,3,3,2,2,2,2,1,1,3,3,3,0},
    {3,3,2,3,3,3,3,1,1,1,1,1,2,3,3,0},
    {3,2,2,2,3,3,2,3,3,1,1,2,2,2,3,0},
    {3,3,2,3,3,3,2,1,3,3,3,3,2,2,2,0},
    {3,3,2,3,3,3,2,3,3,1,1,1,1,2,0,0},
    {3,3,3,3,3,3,2,1,1,1,1,1,0,0,0,0},
    {0,2,2,2,2,2,3,0,0,3,3,3,0,0,0,0},
    {0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0}
};
int linkSpritedownmoving[16][16] = {
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,2,0,1,3,3,3,3,3,3,1,0,2,0,0},
    {0,0,2,0,3,3,3,3,3,3,3,3,0,2,0,0},
    {0,0,2,2,3,2,1,2,2,1,2,3,2,2,0,0},
    {0,0,2,2,3,2,3,2,2,3,2,3,2,2,0,0},
    {0,0,0,2,2,2,2,2,2,2,2,2,2,3,0,0},
    {0,0,0,0,1,2,2,3,3,2,2,1,3,3,0,0},
    {0,0,3,3,3,3,3,2,2,2,1,1,1,2,0,0},
    {0,3,3,2,3,3,3,3,1,1,1,1,1,2,0,0},
    {0,3,2,2,2,3,3,2,3,3,1,1,3,0,0,0},
    {0,3,3,2,3,3,3,2,1,3,3,3,1,2,2,0},
    {0,3,3,2,3,3,3,2,3,3,1,1,1,0,0,0},
    {0,3,3,3,3,3,3,2,1,1,1,3,0,0,0,0},
    {0,0,2,2,2,2,2,0,0,3,3,3,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0}
};

int linkSpriteleft[16][16] = {
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,3,3,3,3,1,1,1,1,1,0,0,0,0},
    {0,0,3,3,3,3,3,3,1,1,2,1,1,1,0,0},
    {0,0,0,3,3,3,3,3,3,2,2,1,1,1,1,0},
    {3,0,0,2,1,2,2,3,2,2,2,1,1,0,1,0},
    {3,2,2,2,3,2,2,3,2,2,3,3,1,0,0,0},
    {3,0,0,2,2,2,2,2,2,3,3,3,0,0,0,0},
    {3,0,0,2,2,2,2,1,1,1,1,0,0,0,0,0},
    {3,0,3,3,3,1,1,1,1,1,1,1,3,0,0,0},
    {3,2,3,3,1,1,1,2,2,2,1,3,3,3,0,0},
    {3,0,3,3,1,1,1,2,2,2,3,3,3,3,0,0},
    {3,0,0,0,3,1,1,1,2,2,3,3,3,3,0,0},
    {3,0,0,0,3,3,3,3,1,1,3,3,1,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0},
    {0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0}
};
int linkSpriteleftmoving[16][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,3,3,3,3,1,1,1,1,1,0,0,0,0},
    {0,0,3,3,3,3,3,3,1,1,2,1,1,1,0,0},
    {0,0,0,3,3,3,3,3,3,2,2,1,1,1,1,0},
    {0,0,0,2,1,2,2,3,2,2,2,1,1,0,1,0},
    {0,2,2,2,3,2,2,3,2,2,3,3,1,0,0,0},
    {0,3,0,2,2,2,2,2,2,3,3,3,0,0,0,0},
    {0,3,0,2,2,2,2,1,1,1,1,0,0,0,0,0},
    {0,3,0,3,3,2,2,2,1,1,3,3,1,0,0,0},
    {0,3,2,3,1,2,2,2,3,3,3,3,3,0,0,0},
    {0,3,0,3,1,1,2,2,3,3,3,3,3,1,0,0},
    {0,3,0,0,3,1,1,1,3,3,3,3,1,1,0,0},
    {0,3,0,1,3,3,3,3,1,1,3,3,1,3,3,0},
    {0,0,3,3,1,1,1,1,1,1,1,1,3,3,3,0},
    {0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0}
};
int linkSpriteright[16][16] = {
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,3,3,3,3,0,0,0},
    {0,0,1,1,1,2,1,1,3,3,3,3,3,3,0,0},
    {0,1,1,1,1,2,2,3,3,3,3,3,3,0,0,0},
    {0,1,0,1,1,2,2,2,3,2,2,1,2,0,0,3},
    {0,0,0,1,3,3,2,2,3,2,2,3,2,2,2,3},
    {0,0,0,0,3,3,3,2,2,2,2,2,2,0,0,3},
    {0,0,0,0,0,1,1,1,1,2,2,2,2,0,0,3},
    {0,0,0,3,1,1,1,1,1,1,1,3,3,3,0,3},
    {0,0,3,3,3,1,2,2,2,1,1,1,3,3,2,3},
    {0,0,3,3,3,3,2,2,2,1,1,1,3,3,0,3},
    {0,0,3,3,3,3,2,2,1,1,1,3,0,0,0,3},
    {0,0,0,1,3,3,1,1,3,3,3,3,0,0,0,3},
    {0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0},
    {0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0}
};
int linkSpriterightmoving[16][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,3,3,3,3,0,0,0},
    {0,0,1,1,1,2,1,1,3,3,3,3,3,3,0,0},
    {0,1,1,1,1,2,2,3,3,3,3,3,3,0,0,0},
    {0,1,0,1,1,2,2,2,3,2,2,1,2,0,0,0},
    {0,0,0,1,3,3,2,2,3,2,2,3,2,2,2,0},
    {0,0,0,0,3,3,3,2,2,2,2,2,2,0,3,0},
    {0,0,0,0,0,1,1,1,1,2,2,2,2,0,3,0},
    {0,0,0,1,3,3,1,1,2,2,2,3,3,0,3,0},
    {0,0,0,3,3,3,3,3,2,2,2,1,3,2,3,0},
    {0,0,1,3,3,3,3,3,2,2,1,1,3,0,3,0},
    {0,0,1,1,3,3,3,3,1,1,1,3,0,0,3,0},
    {0,3,3,1,3,3,1,1,3,3,3,3,0,0,3,0},
    {0,3,3,3,1,1,1,1,1,1,1,1,3,3,0,0},
    {0,0,3,3,3,0,0,0,0,0,3,3,3,0,0,0}
};
D2D1_RECT_F greenrectangle;
D2D1_RECT_F blackrectangle;

inline void drawsquare(ID2D1HwndRenderTarget *pRenderTarget,ID2D1SolidColorBrush *pBrush, int x, int y,int sizey = 3,int sizex=3){
    pRenderTarget->FillRectangle(D2D1::RectF(x,y,x+sizex,y+sizey), pBrush);
}
void drawsprites(ID2D1HwndRenderTarget *pRenderTarget,ID2D1SolidColorBrush *pBrush1,ID2D1SolidColorBrush *pBrush2, int spritetype,int x,int y,ID2D1SolidColorBrush *pBrush3=NULL){
    int (*Sprite)[16];
    switch(spritetype){
        case(0):
            return;
        case(1):
            Sprite = greensprite;
            break;
        case(2):
            Sprite = stonedown;
            break;
        case(3):
            Sprite = stoneup;
            break;
        case(4):
            Sprite = flattree;
            break;
        case(5):
            Sprite = uptree;
            break;
        case(6):
            Sprite = downtree;
            break;
        case(7):
            Sprite = bushsprite;
            break;
        case(8):
            // Sprite = rock;
            break;
        case(9):
            // Sprite = darknut;
            break;
        case(10):
            // Sprite = tree1;
            break;
        case(11):
            // Sprite = tree2;
            break;
        case(12):
            // Sprite = tree3;
            break;
        case(13):
            // Sprite = tree4;
            break;
        case(14):
            Sprite = greensprite;
            break;
        case(15):
            Sprite = stonedown;
            break;
        case(16):
            Sprite = stoneup;
            break;
        case(17):
            Sprite = flattree;
            break;
        case(18):
            Sprite = uptree;
            break;
        case(19):
            Sprite = downtree;
            break;
        case(20):
            Sprite = bushsprite;
            break;
        case(21):
            // Sprite = rock;
            break;
        case(22):
            // Sprite = darknut;
            break;
        case(23):
            // Sprite = tree1;
            break;
        case(24):
            // Sprite = tree2;
            break;
        case(25):
            // Sprite = tree3;
            break;
        case(26):
            // Sprite = tree4;
            break;
        case(27):
            Sprite = greensprite;
            break;
        case(28):
            Sprite = stonedown;
            break;
        case(29):
            Sprite = stoneup;
            break;
        case(30):
            Sprite = flattree;
            break;
        case(31):
            Sprite = uptree;
            break;
        case(32):
            Sprite = downtree;
            break;
        case(33):
            Sprite = bushsprite;
            break;
        case(34):
            // Sprite = rock;
            break;
        case(35):
            // Sprite = darknut;
            break;
        case(36):
            // Sprite = tree1;
            break;
        case(37):
            // Sprite = tree2;
            break;
        case(38):
            // Sprite = tree3;
            break;
        case(39):
            // Sprite = tree4;
            break;
        case(40):
            Sprite = watersprite;
            break;
        case(41):
            Sprite = cavesprite;
            break;
        case(42):
            Sprite = linkSpriteup;
            break;
        case(43):
            Sprite = linkSpritedown;
            break;
        case(44):
            Sprite = linkSpriteleft;
            break;
        case(45):
            Sprite = linkSpriteright;
            break;
        case(46):
            Sprite = linkSpriteupmoving;
            break;
        case(47):
            Sprite = linkSpritedownmoving;
            break;
        case(48):
            Sprite = linkSpriteleftmoving;
            break;
        case(49):
            Sprite = linkSpriterightmoving;
            break;
    }
    if(pBrush1 ==NULL ||pBrush2 == NULL || pBrush3 == NULL){return;}
    for(int i = 0;i<16;i++){
    for(int j = 0;j<16;j++){
        int size = 0;
        for(int test = j;test<16;test++){
            if (Sprite[i][test]==Sprite[i][j]){
                size++;
            }else{
                break;
            }
        }
        switch(Sprite[i][j]){
            case(1):
                drawsquare(pRenderTarget,pBrush1,3*j+x,3*i+y,3,3*size);
                break;
            case(2):
                drawsquare(pRenderTarget,pBrush2,3*j+x,3*i+y,3,3*size);
                break;
            case(3):
                drawsquare(pRenderTarget,pBrush3,3*j+x,3*i+y,3,3*size);
                break;
        }
        j+=size-1;
    }
    }

}
void otherdrawamap(std::vector<int> map,int type, double offsetx,double offsety,ID2D1HwndRenderTarget   *pRenderTarget, ID2D1SolidColorBrush *pBrush1,ID2D1SolidColorBrush *pBrush2,ID2D1SolidColorBrush *pBrush3=NULL){
    int (*Sprite)[16];
    switch(type){
        case(0):
            return;
        case(1):
            Sprite = greensprite;
            break;
        case(2):
            Sprite = stonedown;
            break;
        case(3):
            Sprite = stoneup;
            break;
        case(4):
            Sprite = flattree;
            break;
        case(5):
            Sprite = uptree;
            break;
        case(6):
            Sprite = downtree;
            break;
        case(7):
            Sprite = bushsprite;
            break;
        case(8):
            // Sprite = rock;
            break;
        case(9):
            // Sprite = darknut;
            break;
        case(10):
            // Sprite = tree1;
            break;
        case(11):
            // Sprite = tree2;
            break;
        case(12):
            // Sprite = tree3;
            break;
        case(13):
            // Sprite = tree4;
            break;
        case(14):
            Sprite = greensprite;
            break;
        case(15):
            Sprite = stonedown;
            break;
        case(16):
            Sprite = stoneup;
            break;
        case(17):
            Sprite = flattree;
            break;
        case(18):
            Sprite = uptree;
            break;
        case(19):
            Sprite = downtree;
            break;
        case(20):
            Sprite = bushsprite;
            break;
        case(21):
            // Sprite = rock;
            break;
        case(22):
            // Sprite = darknut;
            break;
        case(23):
            // Sprite = tree1;
            break;
        case(24):
            // Sprite = tree2;
            break;
        case(25):
            // Sprite = tree3;
            break;
        case(26):
            // Sprite = tree4;
            break;
        case(27):
            Sprite = greensprite;
            break;
        case(28):
            Sprite = stonedown;
            break;
        case(29):
            Sprite = stoneup;
            break;
        case(30):
            Sprite = flattree;
            break;
        case(31):
            Sprite = uptree;
            break;
        case(32):
            Sprite = downtree;
            break;
        case(33):
            Sprite = bushsprite;
            break;
        case(34):
            // Sprite = rock;
            break;
        case(35):
            // Sprite = darknut;
            break;
        case(36):
            // Sprite = tree1;
            break;
        case(37):
            // Sprite = tree2;
            break;
        case(38):
            // Sprite = tree3;
            break;
        case(39):
            // Sprite = tree4;
            break;
        case(40):
            Sprite = watersprite;
            break;
        case(41):
            Sprite = cavesprite;
            break;
    }
    
    
    for(int i1 = 0;i1<16;i1++){
    for(int j = 0;j<16;j++){
        int size = 1;
        for(int test = j+1;test<16;test++){
            if (Sprite[i1][test]==Sprite[i1][j]){
                size++;
            }else{
                break;
            }
        }
        switch(Sprite[i1][j]){
            case(1):
                for(int i = 0; i<map.size();i++){
                    int squarey = ((map[i]-1)/16)+offsetx;
                    int squarex = ((map[i]-1)%16)+offsety;
                    int x= 48*(squarex);
                    int y = 48*(squarey)+217;
                    drawsquare(pRenderTarget,pBrush1,3*j+x,3*i1+y,3,3*size);
                }
                break;
            case(2):
                for(int i = 0; i<map.size();i++){  
                    int squarey = ((map[i]-1)/16)+offsetx;
                    int squarex = ((map[i]-1)%16)+offsety;
                    int x= 48*(squarex);
                    int y = 48*(squarey)+217;
                    drawsquare(pRenderTarget,pBrush2,3*j+x,3*i1+y,3,3*size);
                }
                break;
            case(3):
                for(int i = 0; i<map.size();i++){
                    int squarey = ((map[i]-1)/16)+offsetx;
                    int squarex = ((map[i]-1)%16)+offsety;
                    int x= 48*(squarex);
                    int y = 48*(squarey)+217;
                    drawsquare(pRenderTarget,pBrush3,3*j+x,3*i1+y,3,3*size);
                }
                break;
        }
        j+=size-1;
        }
    }
}
void drawamap(std::vector<int> map,int type, double offsetx,double offsety,ID2D1HwndRenderTarget   *pRenderTarget, ID2D1SolidColorBrush *pBrush1,ID2D1SolidColorBrush *pBrush2,ID2D1SolidColorBrush *pBrush3=NULL){
    int (*Sprite)[16];
    switch(type){
        case(0):
            return;
        case(1):
            Sprite = greensprite;
            break;
        case(2):
            Sprite = stonedown;
            break;
        case(3):
            Sprite = stoneup;
            break;
        case(4):
            Sprite = flattree;
            break;
        case(5):
            Sprite = uptree;
            break;
        case(6):
            Sprite = downtree;
            break;
        case(7):
            Sprite = bushsprite;
            break;
        case(8):
            // Sprite = rock;
            break;
        case(9):
            // Sprite = darknut;
            break;
        case(10):
            // Sprite = tree1;
            break;
        case(11):
            // Sprite = tree2;
            break;
        case(12):
            // Sprite = tree3;
            break;
        case(13):
            // Sprite = tree4;
            break;
        case(14):
            Sprite = greensprite;
            break;
        case(15):
            Sprite = stonedown;
            break;
        case(16):
            Sprite = stoneup;
            break;
        case(17):
            Sprite = flattree;
            break;
        case(18):
            Sprite = uptree;
            break;
        case(19):
            Sprite = downtree;
            break;
        case(20):
            Sprite = bushsprite;
            break;
        case(21):
            // Sprite = rock;
            break;
        case(22):
            // Sprite = darknut;
            break;
        case(23):
            // Sprite = tree1;
            break;
        case(24):
            // Sprite = tree2;
            break;
        case(25):
            // Sprite = tree3;
            break;
        case(26):
            // Sprite = tree4;
            break;
        case(27):
            Sprite = greensprite;
            break;
        case(28):
            Sprite = stonedown;
            break;
        case(29):
            Sprite = stoneup;
            break;
        case(30):
            Sprite = flattree;
            break;
        case(31):
            Sprite = uptree;
            break;
        case(32):
            Sprite = downtree;
            break;
        case(33):
            Sprite = bushsprite;
            break;
        case(34):
            // Sprite = rock;
            break;
        case(35):
            // Sprite = darknut;
            break;
        case(36):
            // Sprite = tree1;
            break;
        case(37):
            // Sprite = tree2;
            break;
        case(38):
            // Sprite = tree3;
            break;
        case(39):
            // Sprite = tree4;
            break;
        case(40):
            Sprite = watersprite;
            break;
        case(41):
            Sprite = cavesprite;
            break;
    }
    
    for(int i = 0; i<map.size();i++){
        int squarey = (map[i]-1)/16;
        int squarex = ((map[i]-1)%16);
        int x= 48*(squarex+offsetx);
        int y = 48*(squarey+offsety)+217;
        for(int i1 = 0;i1<16;i1++){
        for(int j = 0;j<16;j++){
            int size = 1;
            for(int test = j+1;test<16;test++){
                if (Sprite[i1][test]==Sprite[i1][j]){
                    size++;
                }else{
                    break;
                }
            }
            switch(Sprite[i1][j]){
                case(1):
                    drawsquare(pRenderTarget,pBrush1,3*j+x,3*i1+y,3,3*size);
                    break;
                case(2):
                    drawsquare(pRenderTarget,pBrush2,3*j+x,3*i1+y,3,3*size);
                    break;
                case(3):
                    drawsquare(pRenderTarget,pBrush3,3*j+x,3*i1+y,3,3*size);
            }
            j+=size-1;
            }
        }
    }
}
void drawmaptype(int level, int type, double offsetx,double offsety,ID2D1HwndRenderTarget   *pRenderTarget, ID2D1SolidColorBrush *pBrush1,ID2D1SolidColorBrush *pBrush2,ID2D1SolidColorBrush *pBrush3=NULL){
    drawamap(settomap(level,type),type,offsetx,offsety,pRenderTarget,pBrush1,pBrush2,pBrush3);
    // std::cout <<settomap(level,type).size();
}
// HRESULT drawmap(HWND hwnd,ID2D1HwndRenderTarget   *pRenderTarget,int level,int level2 = -1,double offsetx =0, double offsety = 0,double offset2x=0, double offset2y=0){
    
//         const D2D1_COLOR_F green = D2D1::ColorF(13.0/256,146.0/256,99.0/256);
//         const D2D1_COLOR_F black = D2D1::ColorF(0.0f,0.0f,0.0f);
//         const D2D1_COLOR_F blue = D2D1::ColorF(0.0f,0.0f,0.75f);
//         const D2D1_COLOR_F map = D2D1::ColorF(0.5f,0.5f,0.5f);    
//         const D2D1_COLOR_F dbrown = D2D1::ColorF(225.0/256,91.0/256,25.0/256);
//         ID2D1SolidColorBrush *pGreenBrush;
//         ID2D1SolidColorBrush *pBlackBrush;
//         ID2D1SolidColorBrush *pMapBrush;
//         ID2D1SolidColorBrush *pBlueBrush;
//         ID2D1SolidColorBrush *pDBrownBrush;
//         HRESULT hr2 = pRenderTarget->CreateSolidColorBrush(green, &pGreenBrush);
//         HRESULT hr3 = pRenderTarget->CreateSolidColorBrush(black, &pBlackBrush);
//         HRESULT hr4 = pRenderTarget->CreateSolidColorBrush(blue, &pBlueBrush);
//         HRESULT hr5 = pRenderTarget->CreateSolidColorBrush(dbrown, &pDBrownBrush);
//         HRESULT hr6 = pRenderTarget->CreateSolidColorBrush(map, &pMapBrush);
//         // printf("%d",level);

//         if (SUCCEEDED(hr2)&&SUCCEEDED(hr3))
//         {
//             drawmaptype(level,1,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level,2,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level,3,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level,4,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level,5,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level,6,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level,7,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush,pBlueBrush);
//             drawmaptype(level,14,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level,15,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level,16,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level,17,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level,18,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level,19,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level,20,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush,pBlueBrush);

//             drawmaptype(level,40,offsetx,offsety,pRenderTarget,pBlueBrush,pDBrownBrush);
//             drawmaptype(level,41,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
            
//             drawmaptype(level2,1,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level2,2,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level2,3,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level2,4,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level2,5,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level2,6,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             drawmaptype(level2,7,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush,pBlueBrush);
//             drawmaptype(level2,14,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level2,15,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level2,16,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level2,17,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level2,18,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level2,19,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             drawmaptype(level2,20,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush,pBlueBrush);

//             drawmaptype(level2,40,offset2x,offset2y,pRenderTarget,pBlueBrush,pDBrownBrush);
//             drawmaptype(level2,41,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             // pRenderTarget->BeginDraw();
//             // // printf("secondsuccess");
//             // drawamap(stonemap,1,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             // drawamap(bushmap,3,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush,pBlueBrush);
//             // drawamap(watermap,4,offsetx,offsety,pRenderTarget,pBlueBrush,pDBrownBrush);
//             // drawamap(cavemap,5,offsetx,offsety,pRenderTarget,pGreenBrush,pBlackBrush);
//             // drawamap(stonebrownmap,1,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush);
//             // drawamap(bushbrownmap,3,offsetx,offsety,pRenderTarget,pDBrownBrush,pBlackBrush,pBlueBrush);
//             // if(level2 != -1){
//             //     drawamap(stonemap2,1,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             //     drawamap(bushmap2,3,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush,pBlueBrush);
//             //     drawamap(watermap2,4,offset2x,offset2y,pRenderTarget,pBlueBrush,pDBrownBrush);
//             //     drawamap(cavemap2,5,offset2x,offset2y,pRenderTarget,pGreenBrush,pBlackBrush);
//             //     drawamap(stonebrownmap2,1,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush);
//             //     drawamap(bushbrownmap2,3,offset2x,offset2y,pRenderTarget,pDBrownBrush,pBlackBrush,pBlueBrush);

//             // }
            
//             pRenderTarget->FillRectangle(D2D1::RectF(0,0,783,217), pBlackBrush);
//             pRenderTarget->FillRectangle(D2D1::RectF(48,97,240,193), pMapBrush);
//             // pRenderTarget->EndDraw();
//         }
//         return hr2&&hr3;
//     // }

//     // return (hr1);
// }
HRESULT drawlink(HWND hwnd, ID2D1HwndRenderTarget *pRenderTarget,int x, int y,int direction,int movesprite){
    const D2D1_COLOR_F green = D2D1::ColorF(182.0/256,248.0/256,31.0/256);
    const D2D1_COLOR_F lbrown = D2D1::ColorF(254.0/256,161.0/256,71.0/256);
    const D2D1_COLOR_F dbrown = D2D1::ColorF(225.0/256,91.0/256,25.0/256);
    ID2D1SolidColorBrush *pGreenBrush;
    ID2D1SolidColorBrush *pLBrownBrush;
    ID2D1SolidColorBrush *pDBrownBrush;
    HRESULT hr1 = pRenderTarget->CreateSolidColorBrush(green, &pGreenBrush);
    HRESULT hr2 = pRenderTarget->CreateSolidColorBrush(lbrown, &pLBrownBrush);
    HRESULT hr3 = pRenderTarget->CreateSolidColorBrush(dbrown, &pDBrownBrush);
    if (SUCCEEDED(hr1)&&SUCCEEDED(hr2)&&SUCCEEDED(hr3))
    {
        drawsprites(pRenderTarget,pGreenBrush,pLBrownBrush,41+direction+4*movesprite,x*3,y*3+217, pDBrownBrush);
    }
    return hr1&&hr2&&hr3;   
}
