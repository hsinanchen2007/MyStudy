```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        lenOfLis = 0
        curr_n = 0
        headnode = ListNode(0)
        headnode.next = head
        curr = headnode
        if head is None:
            return head
    #先获取整个链表的长度
    #删除第倒数第n个节点，其实就是删除顺数第 链表长度-n个节点 
        while curr is not None:
            curr = curr.next
            lenOfLis = lenOfLis + 1
        n_n = lenOfLis - n
        curr = headnode
        while curr is not None:
    #当走到顺数的位置时，直接删除，终止循环
            if curr_n == n_n - 1:
                curr.next = curr.next.next
                break
    #还没走到要删除的点的时候，节点往后移
            else:
                curr = curr.next
                curr_n = curr_n + 1
        return headnode.next
```
