### 解题思路
首先计算链表的总结点数，其次再从头遍历链表，直至到达中间结点。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        ptr=head
        n=0
        while ptr!=None:
            ptr=ptr.next
            n+=1
        r=n//2+1
        ptr=head
        n=1
        while n<r:
            ptr=ptr.next
            n+=1
        return ptr
```

![image.png](https://pic.leetcode-cn.com/afef0595431fa6c43037f422841043e06fce8a4d7100d84528123a9d3adeac5f-image.png)
