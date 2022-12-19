比较经典的做法就是快慢指针法。
当然，也可以转换成数组，时间复杂度不变，空间复杂度会增加一些

快慢指针，顾名思义，需要两个指针，一个快，一个慢，也就是一个每次走一步，一个每次走两步，当快指针走到最后一个元素时，慢指针刚好走到中间位置。而当有偶数个元素时，慢指针指向中间偏左还是偏右，可以使用执行顺序进行控制。题目中要求的是第二个，也就是偏右，因此先走慢指针，然后在走快指针即可。

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # 判断是否为单个结点，如果是单节点，则可以直接输出
        if head.next is None:
            return head
        # 定义快慢指针
        next = head
        fast_next = head

        # 对快慢指针进行移动，直到快指针走到最后一个结点为止
        while fast_next.next is not None:
            next = next.next
            fast_next = fast_next.next
            # 判断是否为偶数个结点(也是最后一个结点)
            if fast_next.next is None:
                break
            else:
                fast_next = fast_next.next
        return next
```
**时间复杂度O(n),空间复杂度O(1)**
