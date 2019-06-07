#include <iostream>
#include "partition.h"
#include "ranker.h"


int main() {
    Block block2 = {{21, 23, 25, 27, 29, 31, 33, 35, 37, 39}, 0, nullptr};
    Block block1 = {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 0, &block2};

    Block block5 = {{22, 24, 26, 28, 30, 32, 34, 36, 38, 40}, 0, nullptr};
    Block block3 = {{2, 4, 5, 8, 10, 12, 14, 16, 18, 20}, 0, &block5};

    Block block4 = {{51, 52, 53, 54, 55, 56, 57, 58, 59, 60}, 0, nullptr};


    Partition partition1 = {&block1};
    Partition partition2 = {&block3};
    Partition partition3 = {&block4};

    Ranker ranker;
    ranker.AddPartiton(&partition1);
    ranker.AddPartiton(&partition2);
    ranker.AddPartiton(&partition3);

    ranker.Rank();
}
