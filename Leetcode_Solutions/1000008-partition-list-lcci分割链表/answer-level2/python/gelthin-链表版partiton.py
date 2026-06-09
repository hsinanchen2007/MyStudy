### 解题思路
同主站习题 [86. 分隔链表](https://leetcode-cn.com/problems/partition-list/)

快排中 partition 的链表实现，题目要求稍微改了一点点：输入 pivot, 不要求 pivot 位于最中间。
这个题目读的非常拗口，读了半天没读懂。
也不说明，partition 后的结果不唯一。



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        i, j = head, head
        while j:
            if j.val < x:   # 如果等于 x 不做处理
                i.val, j.val = j.val, i.val
                i = i.next
            j = j.next
        return head
```