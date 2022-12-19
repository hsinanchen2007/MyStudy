### 解题思路
同习题 [面试题 02.02 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/)

[19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)


只有在删除，插入链表时才会用到虚拟头节点
例如，[21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) ，可以用一个虚拟头结点。


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        
        i, j = head, head
        for _ in range(k):
            if i:  # 也有可能 k 值无效
                i = i.next
        while i:
            i = i.next
            j = j.next
        return j
```