### 解题思路
把链表装进双向队列，然后逐次从首尾取出元素，并赋进`next`，直到取空为止，注意末尾的`next=None`。

### 代码

```python []
class Solution:
    def reorderList(self, head: ListNode) -> None:
        nodes = collections.deque()
        while head:
            nodes.append(head)
            head = head.next
        i, get, node = 0, (nodes.popleft, nodes.pop), ListNode(0)
        while nodes:
            node.next = get[i]()
            i, node = i ^ 1, node.next
        node.next = None
```

![image.png](https://pic.leetcode-cn.com/1e2c4afeb655ce18b7511dd4bf98f9d0a549f8e66876f5a0b63234b825427b46-image.png)
