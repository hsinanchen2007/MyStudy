### 解题思路
计算链表的长度，并根据长度生成随机索引。
进阶：链表长度未知，可以采用[reservior sampling](https://www.***.org/reservoir-sampling/)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def __init__(self, head):
        self.head = head

    def getRandom(self):
        result, node, index = self.head, self.head.next, 1
        while node:
            if random.randint(0, index) is 0:
                result = node
            node = node.next
            index += 1
        return result.val
```