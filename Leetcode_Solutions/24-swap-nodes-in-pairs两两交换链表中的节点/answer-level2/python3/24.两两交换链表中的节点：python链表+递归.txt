### 解题思路
解题思路：使用递归。分为如下情况
1: Basic Case：到头了，也就是head is None or head.next is None。此时我们直接返回head。
2: Recursive Consideration:swapPairs(子列的头节点)返回了一个已经交换过次序的子链表。所以，我们只要将每一次交换后的位于右侧的节点将其连接即可，并且返回交换后的左节点，作为该层子链表的head。
3: 细节：swapping。我们考虑两个节点, head 与 head.next,我们要将其交换成为(原先的)head.next, head。所以我们可以让first = head.next, second = head. Recursive call:子链表可以用first.next来call，并且将其连接至second.
4: 进行了这一系列操作以后，我们可以放心地进行交换：将first的next赋为second，完成链接的让渡。返回这一层的列表head，也就是交换后的first即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        else:
            second = head
            first = head.next
            second.next = self.swapPairs(first.next)
            first.next = second
            return first
```