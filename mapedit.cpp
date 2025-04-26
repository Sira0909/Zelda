#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>

std::string file = "watermap.txt";
std::ifstream textin(file);
int main()
{

    std::string full;
    getline(textin,full);
    std::vector<int> stones;
    int stone = 0;
    for(int i = 0; i<full.size();i++){
        char atpos = full.at(i);
        if (isdigit(atpos)){
            stone*=10;stone+=(int)atpos-(int)(*"0");
            // printf("%d\n",(int)atpos-(int)(*"0"));
        }
        else if(atpos==*(",")){
            stones.push_back(stone);
            
            stone = 0;
        }
    }
    stones.push_back(stone);
    textin.close();
    std::vector<int> levels[128];
    for(int i = 0; i<stones.size();i++){
        int pos = stones.at(i);
        int level = floor(((pos-1)%256)/16);
        level += 16*floor((pos-1)/2816);
        int levelpos = ((pos-1)%16+1)+16*floor(((pos-1)%2816)/256);
        (levels[level]).push_back(levelpos);
    }
    std::ofstream textout(file);
    for(int i = 0; i<128;i++){
        for(int j =0;j<levels[i].size();j++){
            stone = levels[i].at(j);
            if(j>0){
                textout << ",";
            }
            textout<<stone;
        }
        textout<<"\n";
    }
    textout.close();
    return(1);

}
