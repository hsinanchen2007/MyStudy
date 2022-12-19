### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        tmp = head
        middle = self.middleNode(tmp)
        r = middle.next
        middle.next = None
        # 1 2 3   # 5 4
        new_head = self.reverse_list(r)
        res = head
        flag = True
        while head and new_head:
            if flag:
                tmp = head.next
                head.next = new_head
                head = tmp
            else:
                tmp = new_head.next
                new_head.next = head
                new_head = tmp
            flag = not flag
        head = res
        # while res:
        #     print(res.val)
        #     res = res.next

    def reverse_list(self, head: ListNode) -> ListNode:
        if not head:
            return None
        pre = None
        cur = head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre

    def middleNode(self, head: ListNode) -> ListNode:
        # 找到链表中点
        if not head:
            return None
        slow = head
        fast = head
        # fast走两步 slow 走一步
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow


```