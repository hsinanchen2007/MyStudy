### 思路

**快慢指针**

```
快指针每次移动两个位置，慢指针每次移动一个位置。
当快指针到链表尾的时候，慢指针正好到中间位置。
```

**时间复杂度:** O(n)，n 为链表长度。
**空间复杂度:** O(1)

##### Python3代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        # 快慢指针
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0876-Middle-of-the-Linked-List/0876.py)