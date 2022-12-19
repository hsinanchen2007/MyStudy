### 解题思路1：值交换

虽然题目要求不使用值交换来解题，但是可以先从值交换来思考起。

### 代码1

```python
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        pre = head
        post = head.next
        
        # 这是交换值的取巧性质的解决方法
        while pre and post:
            pre.val, post.val = post.val, pre.val
            pre = post.next
            if pre:
                post = pre.next
            else:
                post = None
        
        return head     
```
首先是corner case的判定，如果head是空或者只有一个节点时，直接返回head即可。

然后用pre和post分别跟踪待操作的节点，然后两个节点均非空时，交换两个节点的值。

然后注意pre和post的更新，此时post非空，则pre更新为post.next，然后看post如何更新，因为pre已经指向了当前的post.next，所以如果pre非空，则post指向的是pre.next，否则post = None即可。

这样结果是对的，但是代码难度降低很多。下面考虑如何使用真的交换法完成。

### 解题思路2：交换节点

这个思路需要注意的点在于交换后，当前两个节点组的尾巴还需要在下一个小组更新时指向新的pre，同时还需要注意每个小组的第一个节点的跟踪。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        pre = head
        post = head.next
        dummyHead = post # 交换成功时，则第二个节点是最后的头节点
        
        newStart = None
        tail = None

        while pre and post:
            
            newStart = post.next
            post.next = pre
            pre.next = newStart
            
            if tail:
                tail.next = post
                
            tail = pre

            pre = newStart

            if pre:
                post = newStart.next
            else:
                post = None
            
        return dummyHead
```
用`pre`和`post`表示待操作的一对节点，dummyHead指向第二个节点并最后返回，因为交换后第二个节点是链表的头。

首先在交换前保存好`newStart = post.next`，这是下一个交换对的开始。

然后执行pre和post的交换，post.next = pre，接着pre.next先指向新的交换对的开始，但是注意这并不是最后的。下一对的交换还会触发pre.next的更新，但是pre指针会走，所以用`tail`指针先跟踪`tail = pre`。

此时考虑更新`pre`和`post`。

这个逻辑多思考几遍，并手工模拟几次就很清楚该如何写代码了。

END.