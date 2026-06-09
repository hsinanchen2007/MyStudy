### 解题思路

先创建一个空列表，用p指针在链表上循环并把p.val追加到列表a中，然后反向输出a
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        a = []
        p = head
        
        while p :
            a.append(p.val)
            p = p.next


        return a[::-1]



```