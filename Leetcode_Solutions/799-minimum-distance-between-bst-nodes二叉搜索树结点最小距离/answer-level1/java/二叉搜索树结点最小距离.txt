### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode pre=null;  //pre记录先前节点
    private int res=Integer.MAX_VALUE;
    public int minDiffInBST(TreeNode root) {
        //注意：这个树是二叉搜索树，返回树中任意两节点差的最小值,那中序遍历吧
        dfs(root);
        return res;
    }

    private void dfs(TreeNode root){
        if(root==null)
            return ;
        dfs(root.left);
        if(pre!=null)
        {
            res=Math.min(res,root.val-pre.val);
        }
        pre=root;
        dfs(root.right);
    }
}
```