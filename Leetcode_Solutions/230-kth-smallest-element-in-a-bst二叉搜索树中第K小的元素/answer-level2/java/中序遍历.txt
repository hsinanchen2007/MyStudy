```
class Solution {
    private int count = 0;
    private int val = 0;
    public int kthSmallest(TreeNode root, int k) {
        if(root == null) return -1;
        kthSmallest(root.left,k);
        if(++count==k) val = root.val;
        kthSmallest(root.right,k);
        return val;
    }
    
}
```
