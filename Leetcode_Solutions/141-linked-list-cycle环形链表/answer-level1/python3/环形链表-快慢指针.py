### 解题思路-快慢指针
注意：对于循环链表，设置两个指针`slow, fast`，其中`slow`每次走一步，`fast`每次走两步；最终两者会相遇；

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """
    快慢指针法：
    两个指针：slow,fast；其中slow每次走一步，fast每次走2步；若链表有环，则slow与fast会相遇；
    """
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        slow, fast = head, head.next
        while slow and fast and slow != fast:
            slow, fast = slow.next, fast.next
            fast = fast.next if fast else None

        if fast == None:
            # 没有相遇，走到最后结束循环
            return False
        else:
            # 相遇结束循环
            return True
        

```