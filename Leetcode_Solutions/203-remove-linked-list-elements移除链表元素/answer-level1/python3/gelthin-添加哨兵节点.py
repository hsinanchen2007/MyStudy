### 解题思路

未参看题解前，自己已经想到，如果val出现在head位置，则需要额外处理。
因此，写了一段代码当做预处理，使得处理后 head 处必定不是 val 值，方便后续处理

参考了官方题解，提出了哨兵 sentinel， 即设置一个虚拟头结点，这样便可以把从链表头部删除和从中间删除统一在一起。


### 代码-1

``` python3
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        while (head != None) and (head.val == val):  # 预处理
            pre = head
            head = head.next
            del pre
        
        # 正式处理
        pre = head
        p = head
        while p != None:
            if p.val == val:
                pre.next = p.next
                del p
                p = pre.next
            else:
                pre = p
                p = p.next

        return head
```

### 代码-2

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head
        pre, p = sentinel, head
        while p != None:
            if p.val == val:
                pre.next = p.next
                del p
                p = pre.next
            else:
                pre = p
                p = p.next

        return sentinel.next

            
```