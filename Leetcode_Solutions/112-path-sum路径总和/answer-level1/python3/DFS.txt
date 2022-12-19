## 思路:

其实就是DFS

```python [1]
def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root: return False
        if not root.left and not root.right and sum - root.val == 0:return True
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
```



```java [1]
public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        if (root.left == null && root.right == null && sum - root.val == 0) return true;
        return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val); 
    }
```

相关题型 :  [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)