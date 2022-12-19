1、比较当前节点值与前一节点值，如果比当前节点值小，则需要插入排序；
2、让当前节点脱离链表，用pre.next = cur.next；然后从头遍历（无法从后往前，其实效果都一样），用一个临时链表temp，链表头加了0节点（这样方便只用一个指针遍历）；如果遇到比当前节点值大的，则插入进去：cur.next = temp.next, temp.next = cur;
3、当顺序调整好以后，让当前节点指向pre.next，重复操作
注意：如果这里直接返回head，head始终指着第一个数，则显示不出你排序后的结果。我这里使用了一个小技巧：当当前节点值比前一节点值小时，比较head值与当前节点值的大小，如果当前节点值更小，则让head指向当前节点。
```
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        pre = head
        cur = head.next
        while cur:
            if cur.val < pre.val:
                pre.next = cur.next
                temp = ListNode(0)
                temp.next = head
                if cur.val < head.val:
                    head = cur
                while temp != pre:
                    if temp.next.val > cur.val:
                        cur.next = temp.next
                        temp.next = cur
                        break
                    else:
                        temp = temp.next  
                cur = pre.next
            else:
                pre = cur
                cur = cur.next
        return head       
```

