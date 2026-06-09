![image.png](https://pic.leetcode-cn.com/04bb132cd9fa2e739a6baa9e01071d1e5d83add8003851da691b6f4e3a966e71-image.png)

第一次dfs求所有节点和。第二次dfs判断当前节点左右子树的和是否为总和的一半，是的话设置flag为true，并且flag置为true之后不再递归，直接返回。
```
class Solution {
    boolean flag = false;
    public boolean checkEqualTree(TreeNode root) {
        int sum = getSum(root);
        if (sum % 2 != 0) return false;
        sum /= 2;
        verify(root, sum);
        return flag;
    }

    private int getSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + getSum(root.left) + getSum(root.right);
    }

    private int verify(TreeNode root, int sum) {
        if (root.left == null && root.right == null) {
            return root.val;
        }
        int s = root.val;
        if (root.left != null) {
            int left = verify(root.left, sum);
            s += left;
            if (left == sum) flag = true;
            if (flag) return s;
        }
        if (root.right != null) {
            int right = verify(root.right, sum);
            s += right;
            if (right == sum) flag = true;
            if (flag) return s;
        }
        return s;
    }
}
```