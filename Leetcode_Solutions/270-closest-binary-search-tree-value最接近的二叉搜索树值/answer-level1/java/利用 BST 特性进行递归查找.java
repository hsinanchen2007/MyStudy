### 解题思路
参照官方解题**方法二**，用函数**递归**调用代替 **while** 循环，个人觉得递归调用的**层次更清晰**。

### 代码

```Java
class Solution {
    public int closestValue(TreeNode root, double target) {
        if (root == null) {
            return 0;
        }

        TreeNode node = helper(root, target);
        return node.val;
    }

    private TreeNode helper(TreeNode root, double target) {
        if (root == null || root.val == target) {
            return root;
        }

        TreeNode nextRoot = target < root.val ? root.left : root.right;
        TreeNode node = helper(nextRoot, target);
        return compare(root, node, target);  
    }

    private TreeNode compare(TreeNode root, TreeNode node, double target) {
        if (node == null) {
            return root;
        }

        boolean isRootClosest = Math.abs(root.val - target) < Math.abs(node.val - target);
        return isRootClosest ? root : node;
    }
}
```