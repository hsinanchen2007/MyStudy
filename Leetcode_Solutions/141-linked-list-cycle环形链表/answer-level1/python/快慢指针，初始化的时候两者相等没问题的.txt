### 解题思路
1、需要做空判断，如果head或者head.next为空，则返回false;
2、初始化为fast=low=head没有问题的；
3、每次判断fast以及fast.next，因为这俩只要有空，说明已经结束了；
4、每次fast走两步，low走一步；
5、如果fast==low，则在循环中直接结束了，这是很多N步骤之后的状态；
6、如果跳出了循环，说明结束了；

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        fast = head
        low = head

        while fast and fast.next:
            fast = fast.next.next
            low = low.next

            if fast==low:
                return True
        return False

```