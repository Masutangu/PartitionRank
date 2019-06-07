# PartitionRank

## 定义

* 数据块（Block）：内存中的有序数组
* 分区（Partition）：若干个无相交数据块有序排列组成一个分区

## 问题

对若干分区进行全局排序。

## 算法

类似 merge k sorted list，区别在于时当数据块消费完毕后需要加载分区的下一个数据块：

```c++
if (b->idx + 1 >= DATA_SIZE) {
  // 这个 block 的数据已经读完，读所属 partition 中下一个 block 的数据
  if (b->next) {
      m_pq.push(b->next);
  }
} 
```
