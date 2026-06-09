## 思路
+ 这里只针对第二个一次遍历的方法
+ 用一个快指针，一个慢指针
+ 快指针和慢指针先从头节点开始隔开N个距离
+ 两个指针一起遍历，到快指针到尾巴为止
+ 此时头指针是要删除的节点
+ **为什么需要哑节点？因为如果没有哑结点的话，对于整个链表为空的情况就会很难处理。比如说，链表只有一个结点，并且需要删除这个节点。如果只有head，是很难处理的。如果设置了dummy.next = head，就可以设置dummy.next = None同时返回dummy.next**

## 代码
```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        fast,slow = dummy,dummy
        for  i in range(n+1):
            fast = fast.next
        while fast is not None: 
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return dummy.next
```