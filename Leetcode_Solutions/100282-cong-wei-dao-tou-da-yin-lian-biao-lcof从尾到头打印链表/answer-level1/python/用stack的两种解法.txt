一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
用栈存放，再输出。两种解法。

### 代码

#### 解法1：用辅助栈存储
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reversePrint(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        listNode = head
        stack = []
        result_array = []
        node_p = listNode
        while node_p:
            stack.append(node_p.val)
            node_p = node_p.next 
        while stack:
            result_array.append(stack.pop(-1))
        return result_array
```

#### 解法2：本身栈调用
```
result_array = []
def printListFromTailToHead(listNode):
    # write code here
    if listNode:
        printListFromTailToHead(listNode.next)
        result_array.append(listNode.val)
    return result_array
```