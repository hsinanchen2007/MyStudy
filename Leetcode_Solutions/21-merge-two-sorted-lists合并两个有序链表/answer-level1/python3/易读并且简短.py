### 解题思路
若l1,l2位置不对，就交换，然后可以只写一次递归版本。

### 代码

```python3
#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:return l2
        if l2 is None:return l1

        if l1.val>l2.val:
            l1,l2=l2,l1
        l1.next=self.mergeTwoLists(l1.next,l2)
        return l1
```

### 非递归版本
```python3
  def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        new_node=ListNode(0)
        point=new_node
        while l1 and l2:
            if l1.val<l2.val:
                point.next=l1
                l1=l1.next
            else:
                point.next=l2
                l2=l2.next
            point=point.next
        if l1:
            point.next=l1
        else:
            point.next=l2
        return new_node.next
```