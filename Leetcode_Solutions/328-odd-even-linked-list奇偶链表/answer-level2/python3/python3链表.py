### 解题思路
双指针迭代即可
![UC截图20191214211039.png](https://pic.leetcode-cn.com/6183103202b47fef16bdc64ae08c3c2f4571269f951d7de50185cef9d84f4773-UC%E6%88%AA%E5%9B%BE20191214211039.png)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
            if not head or not head.next or not head.next.next:
                return head
            pre = head
            last = cur = head.next
            while (pre and cur) and (pre.next != None and cur.next != None):
                pre.next = cur.next
                pre = cur.next
                cur.next = pre.next
                cur = pre.next
            pre.next = last
            if cur != None:
                cur.next = None
            return head
```