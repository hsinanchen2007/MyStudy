### 解题思路
从尾至头，反转node的指针方向。


### 代码
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:

        if head == None:
            return []
        if head.next == None :    # 递归终止条件
            return head 

        res = self.reverseList(head.next)

        head.next.next = head    # 修改下一节点的指针
        head.next = None         # 将当前节点的指针设置为空
        
        return res

```
