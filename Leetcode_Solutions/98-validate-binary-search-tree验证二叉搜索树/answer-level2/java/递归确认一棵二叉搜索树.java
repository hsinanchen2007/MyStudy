

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    
    public boolean isValidBST(TreeNode root) {
        int min = Integer.MIN_VALUE;
        int max = Integer.MAX_VALUE;
        return dfs(root, min, max);
    }
    
    // 边界可以会越界, dfs数据接收范围放大到long类型. 计算时, 需要将root.val转成long类型, 否则可能溢出影响结果.
    public boolean dfs(TreeNode root, long min, long max){
        if(root == null) return true;
        if(root.val > max || root.val < min) return false;
        return dfs(root.left, min, (long)root.val-1) && dfs(root.right, (long)root.val+1, max);
    }
    
    
}
```

> 11.26 python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        # 每个节点, 左子树最大 < 根 < 右子树最小
        # 1. 左子树是二叉搜索树
        # 2. 右子树是二叉搜索树
        # 3. 左子树最大值 < 根 < 右子树最小值
            
        self.minval = float("-inf")
        self.maxval = float("inf")
        # def helper(root, upper_bounds, lower_bounds):
        #     if not root:
        #         return True
        #     right = helper(root.right, upper_bounds, root.val)
        #     left = helper(root.left, root.val, lower_bounds)
        #     if not left or not right:
        #         return False
        #     return root.val < upper_bounds and root.val > lower_bounds
        # return helper(root, self.maxval, self.minval)
        def dfs(root, upper_bounds, lower_bounds):
            if not root:
                return True
            if root.val >= upper_bounds or root.val <= lower_bounds:
                return False
            return dfs(root.left, root.val, lower_bounds) and dfs(root.right, upper_bounds, root.val)

        return dfs(root, self.maxval, self.minval)
```