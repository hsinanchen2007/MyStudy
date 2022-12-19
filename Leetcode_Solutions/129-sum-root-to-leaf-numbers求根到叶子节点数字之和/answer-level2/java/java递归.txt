```
class Solution {
    private int ans;
    public int sumNumbers(TreeNode root) {
        preorder(root,0);
        return ans;
    }
    public void preorder(TreeNode root,int sum){
        if(root==null)
            return ;
        sum=sum*10+root.val;
        if(root.left==null&&root.right==null)
            ans+=sum;
        preorder(root.left,sum);
        preorder(root.right,sum);
    }
}
```
