思路：根据二叉搜索树的性质，中序遍历即为一个递增的有序的数字序列，于是题目所求第k小的数，便可以转换为求中序遍历二叉树，第k次访问的节点值。<br/><br/>
于是便有解题代码如下：
```
class Solution {
    int time = 0;// 记录第几次访问
    int ans = 0;// 记录answer
    
    public int kthSmallest(TreeNode root, int k) {
        dfs(root,k);
        return ans;
    }
    
    private void dfs(TreeNode root,int k) {
        if (root == null) {
            return;
        }
        
        dfs(root.left,k);
        
        time++;

        if (time == k) {
            ans = root.val;
            return;
        }
        
        dfs(root.right,k);
    }
}
```