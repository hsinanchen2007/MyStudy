## 思路:

这类题目, 都是[求树的高度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)的延伸版

直接看代码解释

```python [1]
def maxPathSum(self, root: TreeNode) -> int:
        self.res = float("-inf")
        def helper(root):
            if not root: return 0
            # 左边最大值
            left = helper(root.left)
            # 右边最大值
            right = helper(root.right)
            # 和全局变量比较
            self.res = max(left + right + root.val, self.res)
            # >0 说明都能使路径变大
            return max(0, max(left,  right) + root.val)
        helper(root)
        return self.res 
```


```java [1]
class Solution {
    int res = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        helper(root);
        return res;
    }

    private int helper(TreeNode root) {
        if (root == null) return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        res = Math.max(left + right + root.val, res);
        return Math.max(0, Math.max(left, right) + root.val);
    }
}
```

