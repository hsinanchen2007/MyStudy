### 解题思路
典型的宽度优先搜索，使用队列实现宽度优先搜索，FIFO

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        # 层次遍历 BFS宽度优先遍历
        result = []
        if not root:
            return result
        # 使用list实现队列，把第一层结点放进队列
        queues = [root]
        # while 队列不为空，遍历第一层结点，并扩展下一层结点
        while queues:
            size = len(queues)
            cur_level = []
            for _ in range(size):
                #  使用list实现队列，需要记住FIFO，所以每次都需要pop第一个元素，即pop(0)
                node = queues.pop(0)
                cur_level.append(node.val)
                if node.left:
                    queues.append(node.left)
                if node.right:
                    queues.append(node.right)
                    
            result.append(cur_level)
        return result
```
![image.png](https://pic.leetcode-cn.com/0e44ccc29345a1ef7dd460031c014f0ffffcbe235aae322bf80c849e9cb1b4c7-image.png)
