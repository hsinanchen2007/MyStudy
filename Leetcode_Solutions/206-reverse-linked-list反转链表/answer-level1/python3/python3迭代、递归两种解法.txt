
**递归解法**

```python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 递归
        if head is None or head.next is None:
            return head

        ret = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return ret
```

**迭代解法**

```python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 迭代
        pre_node = None
        cur_node = head
        while cur_node is not None:
            next_node = cur_node.next
            cur_node.next = pre_node
            pre_node = cur_node
            cur_node = next_node
        return pre_node
```

>我这个菜鸡都觉得非常简单，没啥好说的- -