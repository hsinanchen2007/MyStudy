评论区高赞的老哥用了一行，我分开把它写开，免得读代码真的被绕死在里面😄，提交时间战胜99.94%
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        if not head or head.next == None:
            return head
        left = head
        mid = head
        todo = head.next
        while todo:
            mid.next = todo.next
            todo.next = left
            left = todo
            todo = mid.next
        return left
        
```
            压缩成一行：mid.next，todo.next，left，todo= todo.next,left,todo,mid.next
说白了就是三个指针：一个指左，一个指中，一个到处乱跑
