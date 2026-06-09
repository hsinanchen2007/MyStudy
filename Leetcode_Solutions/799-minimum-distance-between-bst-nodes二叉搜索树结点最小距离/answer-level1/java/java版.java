### 解题思路
因为二叉树为搜索二叉树，只需要中序遍历，两两相减取最小值即可。

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
    Integer prev,ans;
    public int minDiffInBST(TreeNode root) {
        prev=null;
        ans=Integer.MAX_VALUE;
        dfs(root);
        return ans;
    }
    public void dfs(TreeNode root){
        if(root==null) return;
        dfs(root.left);
        if(prev!=null){
            ans = Math.min(ans, root.val - prev);
        }
        prev=root.val;
        dfs(root.right);
    }
}
```