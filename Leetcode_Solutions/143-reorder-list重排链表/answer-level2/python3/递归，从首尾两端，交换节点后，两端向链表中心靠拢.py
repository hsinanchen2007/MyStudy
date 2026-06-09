```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return None

        left = head
        stop = False
        flag = 1

        def dfs(head):
            nonlocal left,stop,flag
            if not head:
                return 
            dfs(head.next)
            if left.next == head:
                stop = True
                flag = 2
                left.next.next = None
            if left == head and flag == 1:
                stop = True
                head.next = None
            if not stop:
                head.next = left.next
                left.next = head
                left = head.next

        dfs(head)

        return head
```
