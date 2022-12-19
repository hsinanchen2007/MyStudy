### 解题思路
（1）由于m可能是1，所以在头指针前面再添加一个节点。
（2）记录m位置和当前位置，以便后续与反转位置连接
（3）在n位置时将断开的位置连接
（4）[m,n]之间的节点反转

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        i = -1
        l = ListNode(0)
        l.next = head
        head = l
        while(head != None):
            i += 1
            if i == m-1:
                begin = head
                head = head.next
            elif i == m:
                trans = head
                p = head
                head = head.next
            elif i > m and i<n:
                q= head
                head = head.next
                q.next = p
                p = q
            elif i == n:
                q = head
                head = head.next
                q.next = p
                begin.next = q
                trans.next = head
            else:
                head = head.next
        return l.next

```