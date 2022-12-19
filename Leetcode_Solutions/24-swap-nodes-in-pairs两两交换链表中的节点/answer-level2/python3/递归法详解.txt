通过分析，这属于数据结构类型题目，但涉及到多次交换，也需要算法知识。

首先，我想的是，将链表中节点相互交换。
```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        while head.next:
            temp = head.next
            head = temp.next
            temp.next = head
        return head
```
显然这是错误的，因为head发生变化后，头指针找不到了，无法返回链表。这条路行不通。

此时，可以使用递归法：因为递归本质就是不断重复相同的事情。
```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        res = head.next
        head.next = swapPairs(res.next)
        res.next = res
        return res
```
```
递归分步说明：(假定链表为 1->2->3->4->5->6)

第0轮:

head =1

res = 2->...

res.next = 3->...

　　进入第1轮：

　　head = 3

　　res = 4->..

　　res.next = 5->6

　　　　进入第2轮：

　　　　head = 5

　　　　res =6

　　　　res.next = null

　　　　　　进入第3轮:返回null
　　　　回到第二轮：

　　　　head.next =null

　　　　res.next = head(5)

　　　　return  res ( 6->5)

　　回到第一轮：

　　head.next = 6

　　res.next = head(3)

　　return res (4->3->6->5)

回到第0轮：

head.next = 4

res.next =1

return res(2->1->4->3->6->5)
```



