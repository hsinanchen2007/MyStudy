```java
class Solution {
    private int num;
    public int minCameraCover(TreeNode root) {
        if (dfs(root) == 3) {
            num++;
        }
        return num;
    }

    /** 1.安装监视器；2.被监视；3.未被监视 */
    private int dfs(TreeNode root) {
        if (root == null) {
            return 2;
        }
        int left = dfs(root.left);
        int right = dfs(root.right);
        if (left == 3 || right == 3) {
            // 子节点未被监视，因此需要安装监视器
            num++;
            return 1;
        }
        if (left == 1 || right == 1) {
            // 子节点安装了监视器，因此已经被监视
            return 2;
        }
        // 当前未被监视
        return 3;
    }
}
```
