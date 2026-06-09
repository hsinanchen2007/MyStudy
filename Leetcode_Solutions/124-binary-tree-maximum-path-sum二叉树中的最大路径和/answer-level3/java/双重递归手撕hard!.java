### 解题思路
此处撰写解题思路
首先所有可能的最大路径必定以某一个节点为根节点展开
然后每一个可能的最大路径由左链和右链组成，写一个函数求左链长度，一个求右链长度
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
    public int result=-100000;
    public int maxPathSum(TreeNode root) {
        dfs(root);
        return result;
    }
    public void dfs(TreeNode root){
        if(root==null){
            return;
        }
        int left=getPath(root.left);
        int right=getPath(root.right);
        int sum=root.val+Math.max(0,left)+Math.max(0,right);
        if(sum>result){
            result=sum;
        }
        dfs(root.left);
        dfs(root.right);
    }
    public int getPath(TreeNode root){
        if(root==null){
            return 0;
        }
        int left=getPath(root.left);
        int right=getPath(root.right);
        return root.val+Math.max(Math.max(left,right),0);
    }
}
```