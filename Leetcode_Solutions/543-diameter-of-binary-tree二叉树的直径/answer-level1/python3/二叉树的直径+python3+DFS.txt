### DFS(迭代)
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

当前节点的直径就是左右子节点的深度之和，最大直径就是所有节点左右节点的深度之和，代码如下：
```
class Solution:
    def __init__(self):
        self.ans = 0
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.depth(root)
        return self.ans
        
    def depth(self,root):
        if not root:
            return 0
        left = self.depth(root.left)
        right = self.depth(root.right)
        if left+right > self.ans:
            self.ans = left+right
        return 1+max(left,right)
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)