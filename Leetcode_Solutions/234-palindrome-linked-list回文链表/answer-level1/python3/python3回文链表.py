### 解题思路
遍历两次，反转链表一次

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        prev=None
        num1=0
        num2=0
        while head:
            num1=num1*10+head.val
            r=prev
            prev=head
            head=head.next
            prev.next=r
        while prev:
            num2=num2*10+prev.val
            prev=prev.next
        return num1==num2
```

![image.png](https://pic.leetcode-cn.com/5c1d3a91f19a8cbcc929b25574285463d7330d26c19d9651ac50948bbc37c897-image.png)
