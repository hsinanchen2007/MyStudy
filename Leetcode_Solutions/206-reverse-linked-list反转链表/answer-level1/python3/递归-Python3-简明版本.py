### 解题思路
LeetCode官方的递归写的相对比较简洁和迷惑，所以稍微修改一下写了个，个人感觉较为清晰的版本。

1. 建立新的ListNode作为head。
2. 递归的反转当前节点之后的所有节点。
3. 递归外注意相应的修改指针。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        new_head = ListNode(None)

        def recursivor(cur):
            if cur is None or cur.next is None:
                new_head.next = cur
                return cur

            pre = recursivor(cur.next)
            pre.next = cur
            cur.next = None

            return cur

        recursivor(head)

        return new_head.next

```