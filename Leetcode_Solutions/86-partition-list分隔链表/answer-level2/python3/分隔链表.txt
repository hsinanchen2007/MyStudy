### 解题思路

* 方法
    * step1: 建立两个空链表：`dummy1`和`dummy2`。
    * step2：从头遍历节点，如果当前值小于`x`，把节点接到`dummy1`后面，否则接到`dummy2`后面。:
    * step3：把两链表首尾相连，且第二个链表的最后一个节点指向空。
* note：这是二分类问题：小于or大于等于。我一开始分成了三类...所以还是要好好审题啊。
* 时间复杂度：O(N)，空间复杂度：O(1)

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dummy1, dummy2 = ListNode(0), ListNode(0)
        prev1, prev2 = dummy1, dummy2
        curr = head
        while(curr):
            if curr.val < x:
                prev1.next = curr
                prev1 = prev1.next
            else:
                prev2.next = curr
                prev2 = prev2.next
            curr = curr.next
        prev1.next = dummy2.next
        prev2.next = None
        return dummy1.next
```