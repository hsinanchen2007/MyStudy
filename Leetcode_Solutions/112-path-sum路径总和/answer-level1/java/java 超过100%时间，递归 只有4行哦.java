# 其实这么简单的只需要感受代码的魅力吧
## 最后一行是递归求解所有的子叶
[github 精品题解 欢迎start 欢迎打扰 ](https://github.com/ifgyong/leetCode/wiki)
```
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root != null){//该叶子没有子叶然后值等于当前的sum 则返回True
            if (root.left == null && root.right == null && sum==root.val)return true;
        }
        if (root == null)return false;
        return hasPathSum(root.left,sum-root.val)||hasPathSum(root.right,sum-root.val);
    }
}
```