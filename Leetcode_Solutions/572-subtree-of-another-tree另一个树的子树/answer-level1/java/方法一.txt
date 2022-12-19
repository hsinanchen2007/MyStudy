### 解题思路
肯定是需要用到树的遍历，两处核心，
    一是遍历结果的表述形式(String);
    二是拿到s和t的遍历结果后如何确定t是否是s的子树
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        // 前序遍历
        String sPreOrder = preOrder(s, false);
        String tPreOrder = preOrder(t, false);
        return sPreOrder.indexOf(tPreOrder) >= 0;
    }

    private String preOrder(TreeNode treeNode, boolean isLeft) {
        if (treeNode == null) {
            return isLeft ? "leftNull" : "rightNull";
        }
        return String.format("*%s#*%s#*%s#",treeNode.val, preOrder(treeNode.left, true), preOrder(treeNode.right, false));
    }
}
```