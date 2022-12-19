思路：
    遍历节点，交换左右节点就OK！

代码：
```

class Solution {
    public TreeNode invertTree(TreeNode root) {
        comb(root);
        return root;
    }
    public void comb(TreeNode l){
        if(l==null) return;

        TreeNode left=l.left;
        TreeNode right=l.right;
        l.left=right;
        l.right=left;
        
        comb(l.right);
        comb(l.left);
    }
}
```
