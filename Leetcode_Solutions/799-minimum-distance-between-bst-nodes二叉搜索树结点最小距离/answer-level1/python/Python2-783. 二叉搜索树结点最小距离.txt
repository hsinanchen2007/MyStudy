### 解题思路：
看到二叉搜索树的题目，马上要想起来一条关键性质：

__二叉搜索树的中序遍历是升序数组。__

比如对于样例输入 `root = [4,2,6,1,3,null,null]`，中序遍历的结果就是 `[1, 2, 3, 4, 6]`。

题目要求两个结点的最小距离，就是要求中序遍历数组里相邻两个元素差的最小值。
### 代码：
```python [-Python]
class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [node.val] + inorder(node.right)
        
        res = 999999
        l = inorder(root)
        for i in range(1, len(l)):
            res = min(res, l[i] - l[i - 1])
            
        return res
```
### 时空复杂度分析：
中序遍历时每个节点访问了一次，求 `res`时又遍历了整个中序遍历数组，所以
时间复杂度是:$O(2N)$ = $O(N)$。
空间复杂度是:$O(N)$
因为储存了中序遍历的结果。

### 进阶版：
其实可以不用存储中序遍历的结果，而是用一个变量 `pre` 来储存中序遍历上一个节点的值，

这样可以使得空间复杂度降低到 $O(Height)$。
### 代码：
```python [-Python]
class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        def inorder(node):
            if not node:
                return 
            
            inorder(node.left)
            self.res = min(self.res, node.val - self.pre)
            self.pre = node.val
            inorder(node.right)
            
        self.pre = -99999
        self.res = 99999
        inorder(root)
        return self.res
```
