与题112，题113求路径总和问题思路差不多

```
class Solution {
    private int ans = 0;
    private int sum = 0;
    public int sumNumbers(TreeNode root) {
        if(root == null) return 0;
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root){
        //空节点时，return
        if(root == null){
            //ans = ans + sum;
            return;
        }
        //每遍历一个节点，计算临时sum值，一直遍历到叶子节点
        sum = sum * 10 + root.val;
        //叶子节点，将结果添加到ans中
        if(root.left == null && root.right == null){
            ans = ans + sum;
        }
        dfs(root.left);
        dfs(root.right);
        sum = sum / 10;
    }
}
```
