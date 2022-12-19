### 解题思路
- record字典记录所有Node，key是Node,val是Node.val
- 根据val升序，返回对应的key（即Nodes）
- 将Nodes前后相连，返回Nodes[0]作为head即可

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head:return head
        
        record ={}
        while head:
            record[head]=head.val
            head = head.next
        Nodes = sorted(record,key=record.get)
        for i in range(len(Nodes)-1):
            Nodes[i].next = Nodes[i+1]
        Nodes[-1].next = None
        return Nodes[0]
```