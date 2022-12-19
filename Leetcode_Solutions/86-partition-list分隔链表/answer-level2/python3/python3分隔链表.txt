### 解题思路
用两个子链表分别串联比目标值小的和大于等于目标值的，最后再将两子链表连接即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        small=ListNode(-1)
        prevs=small
        large=ListNode(-1)
        prevl=large
        prev=head
        while prev:
            if prev.val<x:
                prevs.next=prev
                prevs=prev
            else:
                prevl.next=prev
                prevl=prev
            prev=prev.next
        prevs.next=large.next
        prevl.next=None
        return small.next
```

![image.png](https://pic.leetcode-cn.com/a1ef6791ce2d42ad4882e0fe131ddd7cd9191eb5b7fd6d49a173fa9af2c37b18-image.png)
