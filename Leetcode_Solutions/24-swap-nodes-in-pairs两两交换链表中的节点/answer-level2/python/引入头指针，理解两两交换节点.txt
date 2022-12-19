### 解题思路
使用头指针，不会丢失链表。
使用头指针指向头结点head：None->1->2->3->4，
Node节点的名字有：pHead和pre
在第一个迭代中：
将pre.next(a)与pre.next.next(b)进行位置上的交换，再将a.next指向b.next实现了箭头的交换，然后挪动pre，变到a的位置，这样就完成了前两个节点的交换。None->2->1->3->4，继续迭代。
最后返回pHead.next（2->1->4->3）

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 定义一个空的头指针
        pHead = ListNode(None)
        #将pHead赋值给pre，head赋值给pre.next
        # 此时，pHead里面的链表形状为：None->1->2->3->4，None对应着pre和pHead
        pre, pre.next = pHead, head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            # a与b调换位置，并且将a的下一位指向b的下一位
            pre.next, b.next, a.next = b, a, b.next
            # pre实现两步移位
            pre = a
        return pHead.next
```