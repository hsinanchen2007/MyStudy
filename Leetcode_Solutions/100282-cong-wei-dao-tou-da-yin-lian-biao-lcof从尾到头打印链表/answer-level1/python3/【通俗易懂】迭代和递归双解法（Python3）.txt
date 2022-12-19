
由于题目要求输出一个数组，而不是类似“第k个，倒数第k个”，因此我们开辟一个N的空间是不算额外复杂度的。 那么我们只需要遍历一次，再反序即可。


## 迭代

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        nodes = []
        cur = head
        while cur:
            nodes.append(cur.val)
            cur = cur.next
        return nodes[::-1]

```

当然其实反序也是没有必要的，我们只需要每次往nodes中插入的时候都往最前面插入即可，这样省了一次遍历，但是时间复杂度没有变化，依旧是$O(N)$

```python
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        nodes = []
        cur = head
        while cur:
            nodes.insert(0, cur.val)
            cur = cur.next
        return nodes
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中N为节点个数，也就是链表长度。
- 空间复杂度：$O(N)$，其中N为节点个数，也就是链表长度。


## 递归


```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if not head:
            return []
        return self.reversePrint(head.next) + [head.val]

```

**复杂度分析**

- 时间复杂度：$O(N)$，其中N为节点个数，也就是链表长度。
- 空间复杂度：由于我们使用了递归，因此栈的空间也是复杂度，栈深度为N，因此空间复杂度为 $O(N)$，其中N为节点个数，也就是链表长度。