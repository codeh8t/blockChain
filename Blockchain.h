// Blockchain.h
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
private:
    int difficulty;
    std::vector<Block> chain;
    Block getLastBlock() const;

public:
    Blockchain();
    void addBlock(Block newBlock);
};

#endif //BLOCKCHAIN_H
