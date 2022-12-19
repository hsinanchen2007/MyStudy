### 解题思路
判断正向列表值与翻转后的列表值是否相等

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:

        stack=[]
        p=head
        while p:
            stack.append(p.val)
            p=p.next
        return stack==stack[::-1]


        

```