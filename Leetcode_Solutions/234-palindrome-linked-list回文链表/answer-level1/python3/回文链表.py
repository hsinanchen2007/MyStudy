### 解题思路
因为链表不能直接定位到最后一个节点，所以可以先遍历链表，将节点的值保存在列表中，然后使用对撞指针，比较left和right指针所指是否相等，若不等就返回False；若相等就同步向内移动，依次比较，直到两个指针相遇。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head is None:
            return True
        result = []
        cur = head
        while cur:
            result.append(cur.val)
            cur = cur.next
        n = len(result)
        left = 0
        right = n - 1
        while left < right:
            if result[left] != result[right]:
                return False
            else:
                left += 1
                right -= 1
        return True

```