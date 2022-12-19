### 解题思路
![SharedScreenshot.jpg](https://pic.leetcode-cn.com/4db777a5d58c18668acbef665b3b8ed8a66d6ce7a57eedbfddda4b300b10bc5c-SharedScreenshot.jpg)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        forward_num = 0
        backward_num = 0
        coor = 1

        while head != None:
            forward_num = forward_num*10 + head.val
            backward_num = backward_num + head.val*coor
            coor *= 10
            head = head.next
    

        return forward_num == backward_num
```