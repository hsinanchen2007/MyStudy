### 解题思路
双指针法很简单，设置指针p、q，让q指针先行n步，然后让p和q一起向后走直到q达到最后一个元素，需要注意的是，这时q指向倒数第一个结点，而p指向倒数第n+1个节点，之所以这样做是方便删除。
这里使用了虚拟头结点的trick，这样在删除头结点的时候不用分类讨论。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        v_head = ListNode(0) # 建立一个虚拟头结点
        v_head.next = head
        p = q = v_head
        for _ in range(n):
            q = q.next
        while q.next:
            p = p.next
            q = q.next
        p.next = p.next.next
        head = v_head.next
        return head
    
```