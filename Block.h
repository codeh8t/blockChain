// Block.h
#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
public:
    std::string previousHash;
    std::string blockHash;
    std::string data;
    long timeStamp;
    int nonce;
    int index;

    Block(int idx, const std::string &dataIn, const std::string &previousHashIn);

    std::string calculateHash() const;
    void mineBlock(int difficulty);
};

#endif //BLOCK_H
