### 迭代

* 两个指针`p1`和`p2`，用于反转; 虚拟头结点`dummy`; 指针`tmp`作为辅助; `prev`指向第m-1个节点。

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        # step1: 将prev移到m-1位，p1移到m-1，p2移到m。
        for i in range(m-1):
            prev = prev.next
        p1 = prev.next
        p2 = p1.next
        # step2：第m位到第n位间的列表进行反转
        for i in range(n-m):
            tmp = p2.next
            p2.next = p1
            p1 = p2
            p2 = tmp
        # step3：处理首尾边界
        prev.next.next = p2
        prev.next = p1
        return dummy.next
```

### 递归

* `reverseN(self, head, n)`函数用于反转1-n位的节点；`reverseBetween(self, head, m, n)`函数用于反转m-n位的节点。


```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == 1:
            return self.reverseN(head, n)
        head.next = self.reverseBetween(head.next, m-1, n-1)
        return head
    def reverseN(self, head: ListNode, n:int) -> ListNode:
        if n == 1:
            self.successor = head.next
            return head
        last = self.reverseN(head.next, n-1)
        head.next.next = head
        head.next = self.successor
        return last
```

