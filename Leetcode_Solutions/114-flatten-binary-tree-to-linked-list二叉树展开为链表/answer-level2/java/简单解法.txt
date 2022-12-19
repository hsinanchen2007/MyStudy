```
class Solution {
    
    //方法1：
    //1.右子树放在左子树的最右节点
    //2.把左子树放在右子树
    //3.右移
    //执行用时 :1 ms, 在所有 Java 提交中击败了99.95%的用户
    public void flatten(TreeNode root) {
        if(root == null) {
            return;
        }
        
        TreeNode lMR = null;
        
        while(root.left != null || root.right != null){
            if(root.left != null){
                lMR = mR(root.left);
                lMR.right = root.right;
                root.right = root.left;
                root.left = null;
            }
            root = root.right;
        }
   
    }
    
    public TreeNode mR(TreeNode root){
        while(root.right != null){
            root = root.right;
        }
        return root;
    }
    
    
    //方法2：
    //使用头节点
    //先序遍历然后逐一连接
    TreeNode head = new TreeNode(0);
    public void flatten(TreeNode root) {
        if(root == null) return;
        
        TreeNode l = root.left;
        TreeNode r = root.right;
        
        head.right = root;
        root.left = null;
        head = head.right;
        flatten(l);
        flatten(r);
    }
}
```
