//
// Created by Masutangu on 2019/6/7.
//

#include <iostream>
#include "ranker.h"
#include "partition.h"


void Ranker::AddPartiton(Partition *partition) {
    m_partition_vec.push_back(partition);
}

void Ranker::Rank() {
    std::vector<int> result; // 存储结果，排序完成输出结果

    for (Partition * p : m_partition_vec) {
        if (p && p->block_list) {
            m_pq.push(p->block_list);
        }
    }

    while (!m_pq.empty()) {
        Block *b = m_pq.top();
        m_pq.pop();
        result.push_back(b->data[b->idx]);

        if (b->idx + 1 >= DATA_SIZE) {
            // 这个 block 的数据已经读完，读所属 partition 中下一个 block 的数据
          if (b->next) {
              m_pq.push(b->next);
          }
        } else {
            // 更新 idx，读取 block 下个 idx 的数据
            b->idx += 1;
            m_pq.push(b);
        }
    }

    for (auto i : result) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}
