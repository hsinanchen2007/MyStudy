### 解题思路
利用列表进行循环遍历
     1 遍历查找值，加入列表中
     2 将head 指向下一个节点
     3 反转打印列表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        res=[]
        while head:
            res.append(head.val)
            head=head.next
        return res[::-1]
```