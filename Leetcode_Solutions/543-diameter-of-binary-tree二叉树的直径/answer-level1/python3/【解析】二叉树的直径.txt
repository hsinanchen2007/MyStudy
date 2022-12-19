### 解题思路
思路是深度优先搜索，这其中有一些参数的设定比较容易搞混，一开始也是错在参数设定的。
self.res是最终结果，一开始设为1，因为它是指的节点数，最后要求边数，是节点数减去一。
然后就是编写一个方法，计算从某一点的左儿子和右儿子开始遍历所得的最大深度之和，这个数加上1（它自己）就是这个点开始的最大节点数，更新self.res用的也是L+R+1。
调用这个方法，最后直接返回self.res-1就是边数了。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res = 1
        def depth(root):
            if root is None:
                return 0
            L = depth(root.left)
            R = depth(root.right)
            self.res = max(self.res, L+R+1)
            return max(L, R) + 1
        depth(root)
        return self.res-1
        
```