// Blockchain.cpp
#include "Blockchain.h"

Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block", "0"));
    difficulty = 4;
}

Block Blockchain::getLastBlock() const {
    return chain.back();
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.previousHash = getLastBlock().blockHash;
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}
