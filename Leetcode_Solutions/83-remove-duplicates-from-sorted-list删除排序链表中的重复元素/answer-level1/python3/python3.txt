### 解题思路
pre为游标指针
while循环：
    pre与pre.next的值比较
    不相等就后移
    相等就将pre.next连到后面的后面（跳过相同元素）元素
直到pre或者pre.next指向None（移到链表尾端） 跳出循环
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode :
        pre = head
        while(pre and pre.next) :
            tmp = pre.next
            if pre.val == tmp.val:
                pre.next = tmp.next
            else:
                pre = tmp
        return head  

```