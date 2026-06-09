### 解题思路
- 遍历一次链表，用record记录所有节点对象
- 删除倒数第N个节点需要分类讨论
- 如果N==len(record),相当于删除头节点；注意如果仅有一个节点返回None,否则返回record[1](跳过头节点)
- 如果N==1,相当于删除尾节点，同样注意如果只有一个节点，返回None;如果不止一个节点，只需record[-2].next = None
- 其他情况，删除链表中节点，只需record[-(n+1)].next = record[-(n-1)],跳过节点record[n]

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        record = []
        while head:
            record.append(head)
            head = head.next
        if n == len(record): 
            if len(record)==1:return None
            else:return record[1]
        if n==1:
            if len(record)==1:return None
            else:
                record[-2].next = None
                return record[0]
        record[-(n+1)].next = record[-(n-1)]
        return record[0]
```