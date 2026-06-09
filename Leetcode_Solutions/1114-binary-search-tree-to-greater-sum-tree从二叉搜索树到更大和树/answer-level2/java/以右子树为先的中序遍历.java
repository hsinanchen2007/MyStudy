```
public class Solution{
    private int sum = 0;

    public TreeNode bstToGst(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode newNode = new TreeNode(root.val);
        newNode.right = bstToGst(root.right);
        newNode.val += sum;
        sum += root.val;
        newNode.left = bstToGst(root.left);
        return newNode;
    }
}
```