

```
public class Solution {
    private Integer tempVal = null;

    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }

        if (!isValidBST(root.left)) {
            return false;
        }

        if (tempVal != null && tempVal >= root.val) {
            return false;
        }

        tempVal = root.val;
        if (!isValidBST(root.right)) {
            return false;
        }

        return true;
    }

    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}

```
