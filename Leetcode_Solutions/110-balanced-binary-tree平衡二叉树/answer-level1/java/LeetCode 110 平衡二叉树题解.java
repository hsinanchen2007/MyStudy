### 解题思路
- 空树是平衡二叉树
- 平衡二叉树的每个子树都是平衡二叉树
- 我的思路是：首先检查根节点的左右子树的深度差是否小于1，如果是，在递归的扫描其子树，如果符合则返回true，否则返回false

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

    private int leftNodeNum;

    private int rightNodeNum;

    public Solution() {
        leftNodeNum = 0;
        rightNodeNum = 0;
    }

    public boolean isBalanced(TreeNode root) {
        if (root != null) {
            leftNodeNum = getNodeDeep(root.left);
            rightNodeNum = getNodeDeep(root.right);
            return Math.abs(leftNodeNum - rightNodeNum) <= 1 && isBalanced(root.left) && isBalanced(root.right);
        }
        return true;
    }

    public int getNodeDeep(TreeNode root) {
        if (root != null) {
            return Math.max(getNodeDeep(root.right), getNodeDeep(root.left)) + 1;
        }
        return 0;
    }
}
```