### 解题思路
此处撰写解题思路

快慢指针反倒比较慢~~~

编译原理，应该可以解释，这是优化和执行的问题。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# keypoint:
# for 求序列长度和index有关时，注意开始的位置和状态，以便推测递推规律，做到心中有数
# 奇数和偶数，分情况讨论清楚后，处理代码
import math
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 定义域 head-》next ！= None
        # 快慢指针,利用两个指针之间的同步关系，潜在、内在的联系
        # 挖掘潜在关系，有利于利用知识
        it = head
        it2 = head
        while it2.next != None:
            it = it.next
            if it2.next.next ==None:
                return it
            it2 = it2.next.next
        return it

            

```