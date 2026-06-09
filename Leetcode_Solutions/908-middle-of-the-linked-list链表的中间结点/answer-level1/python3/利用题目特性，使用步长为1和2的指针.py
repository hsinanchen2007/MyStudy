### 解题思路
双指针法：只需遍历一次链表

**题目中说取中间元素或第2个中间元素**
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 链表只有一个元素
        if head and not head.next:
            return head
        # 定义快慢指针
        fast, slow = head, head

        while slow:
            # 元素个数为奇数的情况，slow指针指向中间节点时，fast指针恰好指向最后一个元素
            if fast and not fast.next:
                return slow

            # 元素偶数为偶数的情况
            # 当slow指向第二个中间节点时，fast将会指向最后一个元素的后面那个空，因此我们需要在fast指向倒数第2个节点进行判断
            if fast.next and not fast.next.next:
                return slow.next

            slow, fast = slow.next, fast.next.next
```