```
class Solution {
    //弊端是使用了全局变量
    private boolean res;
    
    public boolean isBalanced(TreeNode root) {
        this.res = true;
        findDepth(root, 0);
        return res;
    }
    
    private int findDepth(TreeNode node, int curDepth) {
        if( node == null ) {
            return curDepth;
        }
        
        curDepth++;
        int left = findDepth(node.left, curDepth);
        int right = findDepth(node.right, curDepth);
        
        if( Math.abs(left-right) > 1 ) {
            this.res = false;
        }
        // 需要求左右子树各自的最深深度，所以返回max(left, right)
        return Math.max(left, right);     
    }  
}
```
