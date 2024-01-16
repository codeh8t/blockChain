// Block.cpp
#include "Block.h"
#include <sstream>
#include <iostream>
#include <openssl/sha.h>

Block::Block(int idx, const std::string &dataIn, const std::string &previousHashIn) {
    index = idx;
    data = dataIn;
    previousHash = previousHashIn;
    timeStamp = time(nullptr);
    nonce = 0;
    blockHash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timeStamp << data << nonce << previousHash;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, ss.str().c_str(), ss.str().size());
    SHA256_Final(hash, &sha256);

    std::stringstream hashString;
    for (unsigned char i : hash) {
        hashString << std::hex << static_cast<int>(i);
    }
    return hashString.str();
}

void Block::mineBlock(int difficulty) {
    std::string str(difficulty, '0');
    do {
        nonce++;
        blockHash = calculateHash();
    } while (blockHash.substr(0, difficulty) != str);

    std::cout << "Block mined: " << blockHash << std::endl;
}
