```java
class Solution {
    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        preOrder(root, sb);
        return sb.substring(1, sb.length() - 1);
    }

    private void preOrder(TreeNode root, StringBuilder sb) {
        if (root == null) {
            return;
        }
        sb.append("(").append(root.val);
        if (root.left == null && root.right != null) {
            sb.append("()");
        }
        preOrder(root.left, sb);
        preOrder(root.right, sb);
        sb.append(")");
    }

}
```
