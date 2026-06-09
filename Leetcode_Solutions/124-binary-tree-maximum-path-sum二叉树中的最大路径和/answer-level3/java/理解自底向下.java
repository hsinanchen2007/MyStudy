> 草图

![image.png](https://pic.leetcode-cn.com/9c25b8ed39bf1a976efa1f38a9bb7e2e253f1c02bce1793f046fb131e4a3da22-image.png)



```
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
    
    int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        
        dfs(root);
        
        return max;
    }
    
    // 求和路径有可能不经过root结点, 所以只能使用后序遍历
    public int dfs(TreeNode root){
        if(root == null) return 0;
        
        int l = dfs(root.left);
        int r = dfs(root.right);
        l = l < 0 ? 0 : l;
        r = r < 0 ? 0 : r;
        
        max = Math.max(l + r + root.val, max);
        return root.val + Math.max(l, r);
    }
}



```

> 重新理解后写出来的代码

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
    
    int res = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        dfs(root);
        return res;
    }
    
    // 返回每个节点为根的子树的最大和
    public int dfs(TreeNode root){
        if(root == null) return 0;
        int l = dfs(root.left);
        int r =  dfs(root.right);
        
        // 记录整棵树中当前的路径和的最大值
        res = Math.max(res, l + r + root.val);
        
        // 返回当前节点所能取得的最大值(来自root+left, root+right, 0)
        return Math.max(0, Math.max(l,r)+root.val);
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
    def maxPathSum(self, root: TreeNode) -> int:
        #每个节点的最大路径和有三种情况
        #1. 左子树+根 和最大
        #2. 右子树+根 和最大
        #3. 左子树 + 右子树 + 根节点之和最大

        # 当前节点如果为负数, 说明当前节点对于和没有增益, 将根节点值计为0
        self.sum = float("-inf")
        self.update_sum(root)
        return self.sum

    def update_sum(self, root):
        if root is None:
            return 0

        left = max(self.update_sum(root.left),0)
        right = max(self.update_sum(root.right),0)

        cur_sum = max(left, right) + root.val

        self.sum = max(self.sum, left + right + root.val)

        return cur_sum
```