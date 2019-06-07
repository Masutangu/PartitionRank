//
// Created by Masutangu on 2019/6/7.
//

#ifndef PARTITIONRANK_RANKER_H
#define PARTITIONRANK_RANKER_H

#include <vector>
#include <queue>
#include "partition.h"

class Ranker {
public:
    // 比较函数，最小堆
    struct cmpBlock {
        bool operator()(BlockListNode* left, BlockListNode* right) const {
            return left->block[left->idx] > right->block[right->idx];
        }
    };

    // 添加需要排序的分区
    void AddPartiton(Partition* partition);

    // 执行排序
    void Rank();

private:
    std::priority_queue<BlockListNode*, std::vector<BlockListNode*>, cmpBlock> m_pq;
    std::vector<Partition*> m_partition_vec;
};

#endif //PARTITIONRANK_RANKER_H
