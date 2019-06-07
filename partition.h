//
// Created by Masutangu on 2019/6/7.
//

#ifndef PARTITIONRANK_PARTITION_H
#define PARTITIONRANK_PARTITION_H

const int DATA_SIZE = 10;

typedef int Block[DATA_SIZE]; // Block：有序数组

// Block 链表节点
struct BlockListNode {
    Block block;
    int idx; // 当前读取 block 中数据的偏移下标值
    BlockListNode* next; // 所属分区的下一个数据块
};

/*
 * 分区：包含多个无相交的数据块，数据块有序排列，以链表组织
 * Partition: | Block -> Block -> Block|
 */
struct Partition {
    BlockListNode* block_list;
};


#endif //PARTITIONRANK_PARTITION_H
