### 解题思路
第一次遍历确定链表节点个数，并对要旋转的次数取模，第二次将倒数第k个节点确定为链表起始点，并将结尾与开头连接即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        ptr=head
        n=0
        while ptr:
            endlist=ptr
            ptr=ptr.next
            n+=1
        k=k%n
        ptr=head
        ii=0
        while ii<n-k-1:
            ptr=ptr.next
            ii+=1
        endlist.next=head
        head=ptr.next
        ptr.next=None
        return head
```

![image.png](https://pic.leetcode-cn.com/cdf09f539460b51e4f5f64af4f994dfb0ac26f69dbcda0af3e50c20daaacf633-image.png)
