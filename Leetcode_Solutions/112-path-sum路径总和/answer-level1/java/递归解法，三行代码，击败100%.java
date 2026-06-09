![QQ截图20200216001655.png](https://pic.leetcode-cn.com/93ace3947094e43af4a8d8e43e19ff5f081f56a24a8b9e3a94e167cc4b1b5b75-QQ%E6%88%AA%E5%9B%BE20200216001655.png)

问题可以转换为 左子树是否存在路径总和为 sum - root.val的路径 和 右子树是否存在路径总和为 sum - root.val的路径 的或

伪代码为 f(root,sum) = f(root.left,sum - root.val) || f(root.right,sum - root.val)

```
public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        if(root.left == null && root.right == null) return sum == root.val;
        return hasPathSum(root.left,sum -root.val) || hasPathSum(root.right,sum - root.val);
    }
```
别问我为什么不直接 if(root == null) return sum == 0; 因为有个输入是[] 0


