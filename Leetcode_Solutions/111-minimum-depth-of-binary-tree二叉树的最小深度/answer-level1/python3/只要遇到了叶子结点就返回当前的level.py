### 解题思路
1、依然使用queue实现层次遍历，先初始化为root，然后一直循环queue；
2、依然是两层循环，内部循环代表要处理掉本层次所有的节点；
3、为了记录每个层次的节点，queue中每次只存放一层次的节点，然后处理掉；
4、每次记录level，外层循环每一次都把level加一
5、任何时候遇到了叶子结点，就直接返回，这就是最小层次数目；

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        queue = collections.deque([root])
        level = 0
        while queue:
            level += 1
            level_size = len(queue)
            for _ in range(level_size):
                node = queue.popleft()
                if not node.left and not node.right: return level
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)

        return level
    
    
```