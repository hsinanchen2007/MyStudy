1. 两次翻转；
2. 递归；

切题的第一反应是翻转链表后加一，模拟进位解决，然后再将链表反转，时间复杂度是O(n)，但是需要遍历3次链表。第二反应是使用递归的方式进行加一，不进行链表的翻转，这样的时间复杂度也是O(n)，但实际上只遍历了一遍链表，要比第一种方法快一些。

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        def recursion(node: ListNode):
            # 终止条件: 链表尾部节点, 加1后直接返回
            if not node.next:
                node.val += 1
                return
            # 递归下一个节点
            recursion(node.next)
            # 递归完成后处理当前层节点:判断next节点是否大于0, 如果大于9的话, 减10后进位
            if node.next.val > 9:
                node.next.val -= 10
                if node.val:
                    node.val += 1
                else:
                    n = ListNode(1)
                    n.next, node.next = node.next, n


        sentry = ListNode(None)
        sentry.next = head
        recursion(sentry)
        return sentry.next
```

这种方法也是典型的递归模板：

1. 确定终止条件；
2. 处理当前层（该题当前层不需要处理）；
3. 递归调用；
4. 处理当前层状态；
