### 解题思路
Python内部对每个对象都有引用计数，环交叉节点对象的引用计数一定高一些，所以观察各个节点引用计数，发现引用计数大于等于5的就是环交叉节点，所以检测是否有节点引用计数>=5即可;-)
类似的套路也可以去对付[环形链表II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        while head.next:
            if sys.getrefcount(head) >= 5:
                return True
            head = head.next
        return False
```