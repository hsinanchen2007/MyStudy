![image.png](https://pic.leetcode-cn.com/6bf58d351c0173a1ef78ce5744d4833b000a7f063419fe0ef4e88cd18f8dd0d5-image.png)
![批注 2019-10-03 113931.jpg](https://pic.leetcode-cn.com/099d54530e6ed1b0851b5731d553eb4e1147d58a49131199664348e628837aae-%E6%89%B9%E6%B3%A8%202019-10-03%20113931.jpg)

```
public boolean hasPathSum(TreeNode root, int sum) {
        if (root==null)
            return false;
        sum-=root.val;
        if (sum==0&&root.right==null&&root.left==null)
            return true;
        return hasPathSum(root.left, sum)||hasPathSum(root.right, sum);
    }
```
