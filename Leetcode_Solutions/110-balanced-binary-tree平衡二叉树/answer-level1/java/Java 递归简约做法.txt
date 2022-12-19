### 解题思路
递归求解子树的高度，根据高度判断是否平衡。

### 代码

```java
class Solution {
    public boolean isBalanced(TreeNode root) {
        return getBalancedHegiht(root) != -1;
    }


    // 获取平衡树的高度，如果树不平衡 return -1;
    private int getBalancedHegiht(TreeNode root){
        if(root == null) return 0;
        int leftHeight = getBalancedHegiht(root.left);
        if(leftHeight == -1) return -1;

        int rightHeight = getBalancedHegiht(root.right);
        if(rightHeight == -1) return -1;

        if(Math.abs(leftHeight - rightHeight) > 1) return -1;

        return Math.max(leftHeight, rightHeight) + 1;
    }
}
```