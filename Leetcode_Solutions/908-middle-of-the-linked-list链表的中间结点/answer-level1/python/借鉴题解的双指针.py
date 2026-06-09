### 解题思路
本来我是直接循环出一个list，通过的，看了题解的优化后，学习了双指针思路
首先我们让快指针一次走两步
慢指针一次走一步
如果给出的链表的长度是奇数，则快指针跳到最后一个的时候，慢指针刚好跳到中间位置，这时循环的终止条件fast.next 为空
如果给出的链表的长度是偶数，则快指针跳到倒数第二个节点时，慢指针会跳到两个中间节点的前一个，这时继续循环，快指针跳到null，慢指针跳到中间节点的后一个，即结果，此时循环终止的条件为fast为null

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast = head
        slow = head
        while fast and fast.next:
            
            slow = slow.next
            fast = fast.next.next

        return slow

    
```