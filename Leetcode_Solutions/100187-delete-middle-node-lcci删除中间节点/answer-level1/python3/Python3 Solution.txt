### 解题思路
用当前节点取代下一个节点，跳过下一个节点

### 代码
.   
#### 2020.02.21更新
我刚刚发现题目的初始设置和测试用例改了！！！
不过思路是一样的，只是要先找到那个节点。

```
class Solution:
    def deleteNode(self, node: ListNode, n: int) -> None:
        """
        Do not return anything, modify node in-place instead.
        """
        while True:
            if node.val == n:
                node.val = node.next.val
                node.next = node.next.next
                break
            else:
                node = node.next
```



#### 原代码
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
```