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
    //本题实质上还是一个二叉树的深度优先搜索题
    private int MaxLength=0;
    public int longestConsecutive(TreeNode root) {
        dfs(root,null,0);
        return MaxLength;
    }

    private void dfs(TreeNode p,TreeNode parent, int length){
        if(p==null)
            return ;
        length=(parent!=null&&parent.val+1==p.val)? length+1:1;
        MaxLength=Math.max(length,MaxLength);  //更新
        dfs(p.left,p,length);
        dfs(p.right,p,length);
    }
}
```