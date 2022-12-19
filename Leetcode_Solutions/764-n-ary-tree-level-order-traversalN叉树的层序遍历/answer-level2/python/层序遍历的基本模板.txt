### 解题思路
固定模式的层序遍历逻辑，两个list就好
执行用时 : 48 ms, 在所有 Python 提交中击败了81.28%的用户
内存消耗 : 14.9 MB, 在所有 Python 提交中击败了100.00%的用户

### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        result = []
        if not root:
            return result
        curr_level = [root]
        
        while curr_level:
            temp = []
            next_level = []
            for node in curr_level:
                temp.append(node.val)
                next_level += node.children
            result.append(temp)
            curr_level = next_level
        return result


```