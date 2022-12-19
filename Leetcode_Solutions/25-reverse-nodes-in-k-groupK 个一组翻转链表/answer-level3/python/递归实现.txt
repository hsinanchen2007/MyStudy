每次翻转前k个节点，递归。
``` python
def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not self.countEnough(head,k):
            return head
        first_node = head
        move_node = head.next
        new_head = head
        for i in range(k-1):
            first_node.next = move_node.next
            #将下一个节点移动到头节点前
            move_node.next = new_head
            #更新头节点
            new_head = move_node
            #更新要移动的节点
            move_node = first_node.next
        first_node.next = self.reverseKGroup(first_node.next,k)
        return new_head

    #判断链表长度是否大于k
    def countEnough(self,head,k):
        count = 0
        node = head
        while node:
            node = node.next
            count += 1
        return count >= k
```
