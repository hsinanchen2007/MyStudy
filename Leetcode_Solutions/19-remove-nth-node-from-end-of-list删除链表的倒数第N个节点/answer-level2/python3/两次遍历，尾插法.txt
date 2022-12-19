```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 判特殊
        if not head:
            return head

        # 定义一个哑结点用于指向头结点
        dum = ListNode(-1)
        # 使用栈，存储结点
        stack, length = [], 0

        # 求链表长度
        while head:
            stack.append(head.val)
            length += 1
            head = head.next

        # 尾插法，从后往前重新生成链表
        for i in range(length):
            # 要删除的结点,跳过
            if i == n - 1:
                stack.pop()
                continue
            # 链表为空
            if dum.next is None:
                dum.next = ListNode(stack.pop())
            # 链表非空
            else:
                # 创建新结点
                newNode = ListNode(stack.pop())
                # 新结点指向旧结点
                newNode.next = dum.next
                # dum指向新结点
                dum.next = newNode

        return dum.next
```
相比官方题解，复杂了不少，空间复杂度也是增加了。但是完全自己想出来的，还是记录一下。