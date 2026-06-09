```
class Solution {
    int sum = 0;
    public TreeNode convertBST(TreeNode root) {
       
       backOrder(root);
       return root;
    }
    public void backOrder(TreeNode root) {
        if(root == null) {
            return ;
        }
        backOrder(root.right);
        root.val += sum;
        sum = root.val;
        backOrder(root.left);
    }
```