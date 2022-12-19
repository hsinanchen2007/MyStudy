### 解题思路
此处撰写解题思路
bruteforce
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        ans = head
        i=0
        while ans:
            i+=1
            ans = ans.next
        
        if i==1:
            return head 
        if (i %2 ==0):
            for n in range(int(i/2)-1):
                head = head.next
        else:
            for n in range(int((i-1)/2)-1):
                head = head.next
        return head.next

```