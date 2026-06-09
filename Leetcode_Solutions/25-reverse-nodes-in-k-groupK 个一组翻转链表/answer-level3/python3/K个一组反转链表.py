```
def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        m_head = ListNode(0)
        m_head.next = head
        point = m_head

        while point:
            l_node = point.next
            r_node = point

            for i in range(0, k):
                if r_node.next:
                    r_node = r_node.next
                else:
                    return m_head.next

            n1 = l_node
            n2 = n1.next

            point.next = r_node
            l_node.next = r_node.next

            while n2 != l_node.next:
                temp = n2.next
                n2.next = n1
                n1 = n2
                n2 = temp

            point = l_node

        return m_head.next
```