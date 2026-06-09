```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
```
方法一：快慢指针
```
# class Solution(object):
#     def hasCycle(self, head):
#         slow = fast = head
#         while fast and fast.next:
#             slow = slow.next
#             fast = fast.next.next            
#             if slow is fast: return True
#         return False
# 执行用时 :40 ms, 在所有 Python 提交中击败了91.26%的用户
# 内存消耗 :18.3 MB, 在所有 Python 提交中击败了5.86%的用户
```
方法二：哈希表
```
# class Solution(object):
#     def hasCycle(self, head):
#         visited = set()
#         while head:
#             if head in visited:
#                 return True
#             else:
#                 visited.add(head)
#                 head = head.next                
#         return False
# 执行用时 :44 ms, 在所有 Python 提交中击败了80.66%的用户
# 内存消耗 :18.7 MB, 在所有 Python 提交中击败了5.13%的用户
```
方法三：反转链表
```
TODO
```