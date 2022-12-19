```
class Solution {
    
    private HashMap<TreeNode, Integer> hashMap = new HashMap();
    
    private int height(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Integer c = hashMap.get(root);
        if (c != null) {
            return c.intValue();
        }
        
        int res = 1 + Math.max(height(root.left), height(root.right));
        hashMap.put(root, res);
        return res;
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        int a = diameterOfBinaryTree(root.left);
        int b = diameterOfBinaryTree(root.right);
        
        int lh = height(root.left);
        int rh = height(root.right);
        
        int res = Math.max(a, b);
        res = Math.max(res, lh + rh);
        
        return res;
    }
}
```
