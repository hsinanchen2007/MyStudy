### 解题思路
python的递归解法

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def __init__(self):
        self.mk = 0  #存储k值  用于计算何时取head列表内容
        self.ans = None  #存储返回的答案

    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if not head:
            self.mk = k
            return None
        self.getKthFromEnd(head.next,k)
        self.mk -= 1
        if self.mk == 0:
            self.ans = head
        return self.ans
        
```