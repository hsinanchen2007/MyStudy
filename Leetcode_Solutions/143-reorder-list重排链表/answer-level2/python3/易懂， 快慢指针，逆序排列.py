### 解题思路
本题解法多样，各算法性能参差不齐
首先通过快慢指针找到中点位置和末尾位置；
将中点之后的链表进行逆序排列；
将逆序排列后的链表按照顺序插入到中点之前的链表中

### 代码

```python3
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        # 快慢指针找到中点位置
        slow, fast = head, head
        while fast.next:
            slow, fast = slow.next, fast.next
            if not fast.next:
                break
            fast = fast.next
        if slow.next:
            cursor, cursor_next = slow.next, slow.next.next
            # 进行逆序操作
            if cursor_next:
                while cursor_next:
                    temp = cursor_next.next
                    cursor_next.next, cursor, cursor_next = cursor, cursor_next, temp
                slow.next.next = None
            slow.next = None
        # 如果只有一个头节点，就直接返回        
        else:
            return 
        # 插入操作
        cursor = head
        while fast:
            fast_temp = fast.next
            fast.next, cursor.next = cursor.next, fast
            cursor, fast = fast.next, fast_temp

```