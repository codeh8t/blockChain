// main.cpp
#include <iostream>
#include "Blockchain.h"

int main() {
    Blockchain simpleCoin;

    std::cout << "Mining block 1..." << std::endl;
    // For the first block, the previous hash can be a string of zeroes or any other placeholder.
    simpleCoin.addBlock(Block(1, "Block 1 Data", "0"));

    std::cout << "Mining block 2..." << std::endl;
    // For subsequent blocks, you'd typically use the hash of the previous block.
    // Here, for simplicity, we're just using a placeholder string.
    simpleCoin.addBlock(Block(2, "Block 2 Data", "hash_of_block_1"));

    return 0;
}
