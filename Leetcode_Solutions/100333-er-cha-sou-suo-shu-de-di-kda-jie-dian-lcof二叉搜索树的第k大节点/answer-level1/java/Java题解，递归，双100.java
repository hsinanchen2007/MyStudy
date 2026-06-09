```
class Solution {
    int res=0,len=0;  // 递归全局变量，结果值，当前判断位置
    public int kthLargest(TreeNode root, int k) {
        this.len=k;
        inTraverseReversal(root);
        return res;
    }
    // 中序倒序排序的第k个位置
    private void inTraverseReversal(TreeNode root){
        if(root==null) return;
        inTraverseReversal(root.right);
        if(--this.len==0){
            res=root.val;
        }
        inTraverseReversal(root.left);
    }
}
```
