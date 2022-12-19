递归实现，交换每个节点的左右孩子

```
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root == null) return root;
        return reverse(root);
    }

    private TreeNode reverse(TreeNode root){

        if(root.left == null && root.right == null)
            return root;
        if(root.left != null ){
            root.left = reverse(root.left);
        }
        if(root.right != null){
            root.right = reverse(root.right);
        }

        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        return root;
    }
}
```
