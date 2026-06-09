### 解题思路
此处撰写解题思路
主要使用递归的想法

通过递归，从尾部节点开始进行修改。将链表最后一个节点连接上倒数第二个节点上，再返回上一层，对倒数第二个节点进行修改，依次完成节点的修改。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        def reverse(cur):
            if (cur is None) or (cur.next is None):
                return cur
            else:
                p = reverse(cur.next)
                cur.next.next = cur
                cur.next = None
                return p
                
        return reverse(head)
```