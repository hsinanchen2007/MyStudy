### 解题思路
见代码注释

### 代码

```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        '''
        用递归方式反转链表的前n个节点，注意要记录第n+1个节点（为反转后链表的后继节点），
        返回反转后的子链表的头指针
        '''
        successor = None
        def reverse(head, n):
            global successor
            if n == 1:
                successor = head.next  # 反转后链表的后继节点
                return head
            last = reverse(head.next, n-1)  # 把reverse(head.next, n-1)看做是：一个已经实现了 反转以head.next为头结点的前n-1个节点的功能，且返回了新的头结点。不要跳进递归，⽽是利⽤明确的定义来实现算法逻辑。
            head.next.next = head
            head.next = successor
            return last

        # 整个都采用递归方式
        # if m == 1:
        #     return self.reverse(head, 1, n)
        # else:
        #     return self.reverseBetween(head.next, m-1, n-1)

        # 边缘情况
        if m == n:
            return head
        if m == 1:
            return reverse(head, n)

        # 迭代，找第m-1个节点
        res = head
        t = m
        while t > 2 and head.next != None:
            head = head.next
            t -= 1
        precursor = head  # 第m-1个节点即为 反转后的子链表的前驱节点

        last = reverse(head.next, n-m+1)  # 需要注意是n-m+1
        precursor.next = last
        return res
```