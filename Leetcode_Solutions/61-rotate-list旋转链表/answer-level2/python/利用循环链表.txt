### 解题思路
此处撰写解题思路
先将首尾连接变成循环列表，然后再寻找旋转后的头指针并断开连接
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, n, k):
        if not n:return n
        h=n
        d=0
        while True:
            d+=1
            if not n.next:
                n.next=h
                break
            n=n.next
        d=d-k%d
        for i in range(d-1):
            h=h.next
        n=h.next
        h.next=None
        return n
```