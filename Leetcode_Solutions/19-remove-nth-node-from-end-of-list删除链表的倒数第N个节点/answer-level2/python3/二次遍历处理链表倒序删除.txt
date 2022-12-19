两次遍历：
1. 第一次遍历整条链表，返回链表的长度，并计算目标元素的正序序号
2. 第二次遍历根据正序序号将目标元素上一结点的next指向目标元素的下一结点即可
3. 遍历之前在链表最前端设置一个哑结点，来避免极端情况：比如链表只有一个元素、要删除链表的第一个元素等等

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        prehead = ListNode(-1)
        prehead.next = head
        h = head
        length = 0

        """
        计算链表的长度
        """
        while(h):
            length += 1
            h = h.next

        """
        删除正序位置的目标元素
        """
        target = length - n 
        h = prehead
        index = 0
        while(index < target):
            index += 1
            h = h.next

        h.next = h.next.next

        return prehead.next # 为何这里 return head 就错