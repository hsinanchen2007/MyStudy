## 迭代法

主要就是需要两个指针，在我们迭代的过程中 `prev` 和 `curr` 之间是没有指针连接的，所以需要我们用2个指针来确定他们在哪。

```
  prev  curr
   |     |
1->2     3<-4<-5
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        
        while curr != None:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        
        return prev
```

## 递归

主要就是让当前的下下个指向自己，开始情况
```
1->2->3->4->5，
```
这里 `last` 是 5，head是1，我们只需要考虑这一行递归的代码会使得后面4个节点翻转就够了，具体怎么做的不用想，也容易想错，那么现在就是这样
```
1->2<-3<-4<-5
```
我们只需要让1的指针指向正确位置就行了，如代码所示

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        last = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        
        return last
```