#include <iostream>
#include <cstdio>
#include "FileIterator.hxx"

using sh_ptr = std::shared_ptr<std::vector<std::string>>;
int main(int argc, const char * argv[]) {
    FileIterator file("/Users/sinamoghimi/Documents/Codes/GitHub/Advent-of-Code/Day 2/input.txt", '\n');
    sh_ptr list{file.GetTokens()};
    
    size_t pos{}, depth{};
    std::string direction{}, amount{};
    for (const std::string &s : *list){
        std::istringstream stream(s);
        stream >> direction >> amount;
        if(direction.compare("forward") == 0)
            pos += std::stoul(amount);
        else
            depth += ((direction.compare("down") == 0)?1:-1)*std::stoul(amount);
    }


    std::cout << "Pos * Depth: " << (pos * depth) << "\n";
    
    
    return 0;
}

