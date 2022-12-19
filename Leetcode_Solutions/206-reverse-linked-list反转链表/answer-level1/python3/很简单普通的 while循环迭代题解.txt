### 解题思路
代码中有注释,直接看注释吧

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur_node = head
        k = None # None用于清空head的next值
        while cur_node is not None: 
            temp = cur_node.next #零时存储下一个节点
            cur_node.next = k # 本节点的next指向k
            k = cur_node # k存储当前节点带入下一次循环
            cur_node = temp # 当前节点替换成下一节点进入下一轮循环
        return k #返回反转后的头节点(原来顺序的最终节点)
```