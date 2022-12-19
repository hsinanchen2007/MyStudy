### 解题思路
新建立一个列表，然后将链表输出的值插入到列表的头中，然后打印出来此列表就OK了

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        out = []
        pTmp = head
        while pTmp:
            out.insert(0,pTmp.val)
            pTmp = pTmp.next
        return out
```