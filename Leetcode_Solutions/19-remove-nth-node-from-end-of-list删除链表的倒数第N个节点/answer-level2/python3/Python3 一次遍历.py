### 解题思路
一次遍历，放到列表里面，然后就很好处理了。但是有几个边界的地方需要特别注意。
![image.png](https://pic.leetcode-cn.com/d8b4be33697dded128302889d3078972c4f2af308b592c017f8988d84370b374-image.png)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node_list = []
        while head:
            node_list.append(head)
            head = head.next

        if len(node_list) == 1:
            return None
        elif n == 1:
            node_list[-2].next = None
            return node_list[0]
        elif n == len(node_list):
            node_list[0].next = None
            return node_list[1]
        elif n < len(node_list):
            node_list[-(n+1)].next = node_list[-(n-1)]
            return node_list[0]

```