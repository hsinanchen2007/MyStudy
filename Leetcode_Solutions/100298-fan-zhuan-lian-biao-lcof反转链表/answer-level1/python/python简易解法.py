一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
假设翻转1->2->3->4->5，步骤如下：

```
head->4->3->2->1->5
               p  tp
```
- 1.我们将p的next指向tp的next
- 2.将tp的next指向head的next
- 3.将head的next指向tp

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, pHead):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not pHead: return None
        head = ListNode(0)
        head.next = pHead
        p = pHead
        while(p.next):
            tp = p.next
            p.next = p.next.next
            tp.next = head.next
            head.next = tp
        return head.next
```