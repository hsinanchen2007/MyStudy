### 解题思路
以两两节点为一组，prev保存指向当前组节点的上一节点，结尾需要断开原有指针以避免陷入循环。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return head
        prev=ListNode(-1)
        lowptr=head
        fastptr=head.next
        if fastptr:
            head=fastptr
        while fastptr:
            r=fastptr.next
            prev.next=fastptr            
            fastptr.next=lowptr
            prev=lowptr
            lowptr=r
            if lowptr:
                fastptr=lowptr.next
            else:
                fastptr=None
        prev.next=lowptr
        return head
```

![image.png](https://pic.leetcode-cn.com/adde06156924663f9126538b8da3409646e50e3d572e3b3e3ee873c665935832-image.png)
