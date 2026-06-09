### 解题思路
由于倒数第k个节点的下标为n-k，其中n为链表的长度。可以先设一个指针temp，指向head，先让temp走k步，则此时剩下的链表长度为n-k，再让temp和head同时走，直到temp到达尾部，此时head指向的节点值即为所求。
![QQ截图20200301121329.png](https://pic.leetcode-cn.com/e36a06a8286315e34724ba5f2df9427db085fd4056a9a9fb7db944d37e263d74-QQ%E6%88%AA%E5%9B%BE20200301121329.png)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        if not head:
            return
        temp = head
        # 先让temp走k步
        while k > 0:
            temp = temp.next
            k -= 1
        # head和temp同时走，temp走到尾，此时head即到目标
        while temp:
            temp = temp.next
            head = head.next
        return head.val
```