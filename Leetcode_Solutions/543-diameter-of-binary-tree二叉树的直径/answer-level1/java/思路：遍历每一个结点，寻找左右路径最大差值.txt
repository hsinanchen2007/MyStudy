```java
class Solution {
    private int ans = 0;//存放答案
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        recursive(root);
        return ans;
    }

    //递归寻找左右路径最大差值
    private int recursive(TreeNode root) {
        //左边路径长度
        int left = root.left == null ? 0 : recursive(root.left) + 1;
        //右边路径长度
        int right = root.right == null ? 0 : recursive(root.right) + 1;
        //左右路径最大差值更新
        ans = Math.max(ans, left + right);
        //返回给上级作为子树的最大路径
        return Math.max(left, right);
    }
}
```
