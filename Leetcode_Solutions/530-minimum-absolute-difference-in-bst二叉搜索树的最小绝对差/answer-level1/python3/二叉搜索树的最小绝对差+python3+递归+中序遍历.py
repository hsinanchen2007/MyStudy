### 递归
根据二叉搜索树的特点，利用两个辅助函数找到当前节点的最小绝对差，再递归的求左右节点的最小绝对差，最终求出最小值。代码如下：
```
class Solution:
    def find_left(self,root):
        if not root:
            return -10000
        while root.right:
            root = root.right
        return root.val
    def find_right(self,root):
        if not root:
            return 10000
        while root.left:
            root = root.left
        return root.val
    
    def getMinimumDifference(self, root: TreeNode) -> int:
        if not root:
            return 10000
        else:
            l = root.val - self.find_left(root.left)
            r = self.find_right(root.right)-root.val
            left = self.getMinimumDifference(root.left)
            right = self.getMinimumDifference(root.right)
            return min(l,r,left,right)
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)

### 中序遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

采用递归的方式中序遍历，得到一组遍历数组，再求最小值。代码如下：
```
class Solution: 
    def getMinimumDifference(self, root: TreeNode) -> int:
        def preorder(root):
            if not root:
                return []
            else:
                return preorder(root.left)+ [root.val] + preorder(root.right)
        target = preorder(root)
        n = len(target)
        min_ = 10000
        for i in range(n-1):
            min_= min(target[i+1]-target[i],min_)
            
        return min_
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)