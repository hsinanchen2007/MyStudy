执行用时 : 0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :36.2 MB, 在所有 java 提交中击败了78.76%的用户
```
class Solution {  
    public int sumOfLeftLeaves(TreeNode root) {
        if(root==null){
            return 0;
        }
        int ans=0;
        TreeNode left=root.left;
        if(root.left!=null&&left.left==null&&left.right==null){
            ans+=root.left.val;
        }
        ans+=sumOfLeftLeaves(root.left)+sumOfLeftLeaves(root.right);
        return ans;
    }
}
```
