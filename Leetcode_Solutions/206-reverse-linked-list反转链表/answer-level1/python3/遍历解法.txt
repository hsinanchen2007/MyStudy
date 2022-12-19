### 解题思路
遍历链表进行反转，用pre指针完成翻转并成为新的头指针，
在进行遍历时，1.首先用tmp保存下一结点（确保撤掉连接后不丢失下一结点）；
2.撤掉当前结点跟下一结点的连接，连到pre上一节点去
3.前进，当前结点变成pre结点，下一节点变成当前结点。

最后返回新的头指针pre即可。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre=None
        cur=head
        while cur:
            tmp=cur.next
            cur.next=pre
            pre=cur
            cur=tmp
        return pre
```