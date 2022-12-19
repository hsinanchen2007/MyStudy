### 解题思路
思路都写在代码里面了~

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        '''因为转换两个节点不仅仅是两节点之间的关系，这样调换之后就会丢失后继节点，形成环。所以需要第三个节点来做后继的保存。链表的题目画图有利于理解，虽然画起来挺麻烦的，最好用铅笔画，好擦~'''
        # if not head:return None     #考虑特殊情况
        # prev = None                 #prev需要事先初始化，而且不能用ListNode来初始化。

        # while head:
        #     next = head.next        #保存head后面的一个节点

        #     head.next = prev        #核心！ 将当前节点的后继节点指向前继节点

        #     prev = head             #这两行是将节点整体往后移
        #     head = next
                
        # return prev

        # if not head or not head.next:return head
        # p = self.reverseList(head.next)
        # head.next.next = head
        # head.next = None
        # return p

        cur, prev = head, None          #这是极客时间他们的代码，真的很简洁！
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        return prev
```