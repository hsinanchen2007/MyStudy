DFS法 在JAVA中击败了100%的用户
```
class Solution {
    int ans;
    public int sumRootToLeaf(TreeNode root) {
        dfs(root,0);
        return ans;
    }
    public void dfs(TreeNode root,int sum){
        if(root==null)return ;
        sum=sum<<1;
        sum+=root.val;
        if(root.left==null&&root.right==null)
            ans+=sum;
        dfs(root.left,sum);
        dfs(root.right,sum);
    }
}
```
