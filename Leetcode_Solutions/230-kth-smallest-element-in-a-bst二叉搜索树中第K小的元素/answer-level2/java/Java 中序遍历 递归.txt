中序遍历,用一个计数器`count`,倒数至0时，为结果`res`赋值.  
`dfs(root)`第一行的代码`if(count == 0) return;`删掉也能得到结果。
但是其可以在找到目标值后，立刻立刻返回，避免多余递归，显著提高速度。
```
class Solution {
    private int count;
    private int res = -1;
    
    public int kthSmallest(TreeNode root, int k) {
        count = k;
        dfs(root);
        return res;
    }
    
    public void dfs(TreeNode root) {
        if(count == 0) return; 
        if(root.left != null) dfs(root.left);
        count--;
        if(count == 0) res = root.val;
        if(root.right != null) dfs(root.right);
    }
}
```
