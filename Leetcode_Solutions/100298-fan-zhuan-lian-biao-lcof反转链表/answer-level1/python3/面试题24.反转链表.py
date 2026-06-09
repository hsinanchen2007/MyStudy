### 解题思路
- 维护一个指针指向链头，向后遍历节点，节点不断地插入成为链头（头插法）
- 下面两个代码思路一样的，但是第一个可读性比较差
- 特别注意，name = ListNode() 与 name.next = ListNode()区别，才不会乱

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # def reverseList(self, head: ListNode) -> ListNode:
    #     if not head:return head
    #     dumy = ListNode(0)
    #     while head:
    #         dumy.next, head.next, head  =  head, dumy.next,head.next
    #     return dumy.next
   
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:return head
        dumy = ListNode(0)
        dumy.next , cur = head, head.next
        dumy.next.next = None 
        while cur:
            dumy.next, cur.next, cur  =  cur, dumy.next,cur.next
        return dumy.next


```