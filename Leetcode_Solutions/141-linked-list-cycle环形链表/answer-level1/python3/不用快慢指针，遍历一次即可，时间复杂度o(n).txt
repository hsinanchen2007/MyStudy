### 解题思路
执行用时 : 52 ms , 在所有 python3 提交中击败了 90.09% 的用户
内存消耗 : 14 MB , 在所有 python3 提交中击败了 100.00% 的用户

只需要新建一个`mynode`，在每遍历一个新node的时候，将它的`next`指向自己创建的`mynode`，假如遍历到了`mynode`，就意味着有环路。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        mynode = ListNode(True)
        while head != None:
            temp = head.next
            head.next = mynode
            head = temp
            if head == mynode:
                return True
        return False
```