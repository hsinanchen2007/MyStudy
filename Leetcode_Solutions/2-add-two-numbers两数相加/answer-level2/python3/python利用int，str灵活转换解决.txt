### 解题思路
此处撰写解题思路
其实这个本质就是两个数相加，所以我们不如把这个转换成int型的数字
然后相加之后把每个位置上取出来放入ListNode

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        s1 = ''
        s2 = ''
        while l1 is not None:
            s1 = str(l1.val)+s1
            l1 = l1.next
        while l2 is not None:
            s2 = str(l2.val)+s2
            l2 = l2.next
        s3 = str(int(s1)+int(s2))
        l = len(s3)
        li = ListNode(int(s3[0]))
        for i in range(1,l):
            f = ListNode(int(s3[i]))
            f.next = li
            li = f 
        return li
```