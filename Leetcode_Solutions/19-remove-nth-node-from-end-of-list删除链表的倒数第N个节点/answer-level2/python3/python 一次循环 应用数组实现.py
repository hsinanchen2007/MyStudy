```
def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        tmp = head
        node_list = []
        while tmp:
            node_list.append(tmp)
            tmp = tmp.next

        node = node_list[-n]
        if node == node_list[0]:
            result = node.next
            node = None
            return result
        elif node == node_list[-1]:
            node_list[-2].next = None
            return node_list[0]
        else:
            node = None
            pre = node_list[-n-1]
            pre.next = node_list[-n+1]
            return node_list[0]
```
