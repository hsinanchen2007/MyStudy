
`注意：路径不需要从根节点开始，也不需要在叶子节点结束。路径方向必须向下，不能跳着走，路径必须连续。`

在之前的[PathSum(112题)](https://leetcode-cn.com/problems/path-sum/)中可以递归去找f(左子树)能不能达到sum-root.val 或者 f(右子树)能不能达到sum-root.val,相当于默认了root一定在组成sum的路径中。

对于这个问题而言，root不一定在组成sum的路径中，此时就应该分情况讨论

- 情况1.如果root在组成sum的路径中的话，然后就去 寻找左子树作为根节点的组成 sum-val 的路径 和 寻找右子树作为根节点的组成 sum-val 的路径，递归下去
- 情况2.如果root不在组成sum的路径中，那么就去 寻找左子树作为根节点的组成 sum 的路径 和 寻找右子树作为根节点的组成 sum 的路径，递归下去

**pathSum(root, sum)函数**定义：在root为根节点的二叉树中，寻找和为sum的路径数，**root不一定在path中**
**findPath(root, sum)函数**定义：在root为根节点的二叉树中，寻找和为sum的路径数，**root在path中**

```python
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def findPath(root, sum):
            if root == None:
                return 0
            res = 0
            if root.val == sum:
                #在其后面的子树中可能加加减减又等于sum了，所以现在不能直接return，还要继续寻找可能的路径，此时作为一条路径加一
                res += 1
            res += findPath(root.left, sum-root.val)
            res += findPath(root.right, sum-root.val)
            return res
            
        if root == None:
            return 0
        
        # 情况一，包含root的情况
        res = findPath(root, sum) 

        #情况二,不包含root的情况。注意pathSum(root, sum)函数定义：在root为根节点的二叉树中，寻找和为sum的路径数，root不一定在path中
        res += self.pathSum(root.left, sum)
        res += self.pathSum(root.right, sum)
        
        return res
```
