**这道题，用指针来解很简单，先用两个指针指着head头部的地址。第一个指针用来取head链表中的所有value，并利用insert方法实现值得倒序。第二个指针来改变head中的值，对取出来的值进行遍历，然后通过移动指针来改变head中的值。**

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        mid_val = head
        sec_val = head
        a = []
        while mid_val:
            a.insert(0,mid_val.val)
            mid_val = mid_val.next
        for i in a:
            sec_val = i
            sec_val = sec_val.next
        return head
```
