//
// Created by Masutangu on 2019/6/7.
//

#ifndef PARTITIONRANK_PARTITION_H
#define PARTITIONRANK_PARTITION_H

const int DATA_SIZE = 10;

// 数据块
struct Block {
    int data[DATA_SIZE]; // 有序数组
    int idx; // 当前读取 data 数组中的偏移下标值
    Block* next; // 所属分区的下一个数据块
};

/*
 * 分区：包含多个无相交的数据块，数据块有序排列，以链表组织
 * Partition: | Block -> Block -> Block|
 */
struct Partition {
    Block* block_list;
};


#endif //PARTITIONRANK_PARTITION_H
