### 解题思路
此处撰写解题思路
1. 构造一个队列，把树放进去；
2. 解决方法与该题的解决方案一样[填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/shi-yong-zhan-jie-jue-by-xuhui11-4/)
3. 区别在于多了一些判断条件，左、右节点都有可能为None的情况；
### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return root
        node = root
        stack = [root]
        while len(stack) != 0:
            n = len(stack)
            right = None
            for i in range(n):
                temp = stack.pop(0)
                if i == n - 1:
                    temp.next = None
                if temp.left:
                    if right:
                        right.next = temp.left
                    if temp.right:
                        stack.append(temp.left)
                        stack.append(temp.right)
                        temp.left.next = temp.right
                        right = temp.right
                    else:
                        stack.append(temp.left)
                        right = temp.left
                else:
                    if temp.right:
                        if right:
                            right.next = temp.right
                        stack.append(temp.right)
                        right = temp.right
        return node

        
```