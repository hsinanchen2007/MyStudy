### 解题思路

重点还是在虚拟头部节点，没有想到还可以这么搞；

### 代码

```python3
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 维护一个虚拟的头部节点，可以随时回到这个跟踪的链表
        preNode = ListNode(-1)
        # 这里还需要一个指针pre；这个地方没有想到；
        pre = preNode
        # l1和l2都不为空时一直循环
        while l1 and l2:
            # 如果l1的第一个节点小于等于l2的第一个节点，preNode.next指向小的节点，也就是l1，l1的当前节点变成l1.next
            if l1.val <= l2.val:
                pre.next = l1
                l1 = l1.next
            else:
                pre.next = l2
                l2 = l2.next
            # pre = pre.next 为什么放在while循环里，放在外面就拿不到前面的值了，是出了while循环后while内的值就被释放了吗
            #  pre.next指向下一个节点，pre = pre.next意思是pre这个指针移到了下一个节点。
            pre = pre.next
        # if l1 or l2 is none
        pre.next = l1 if l1 is not None else l2
        # 这里的next跳过了最开始设置的虚拟头部节点的值-1
        return preNode.next
```