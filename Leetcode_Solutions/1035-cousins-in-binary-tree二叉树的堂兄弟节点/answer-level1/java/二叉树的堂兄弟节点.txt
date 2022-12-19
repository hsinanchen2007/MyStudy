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
    public boolean isCousins(TreeNode root, int x, int y) {
        int [] resX=dfs(root,root,x,0);
        int [] resY=dfs(root,root,y,0);
        return resX[0]!=resY[0]&&resX[1]==resY[1];
    }

    public int [] dfs(TreeNode parent,TreeNode node,int val,int level)
    {
        if(node==null)
            return null;
        if(node.val==val)
            return new int[]{parent.val,level};
        int [] left=dfs(node,node.left,val,level+1);
        int [] right=dfs(node,node.right,val,level+1);
        return left==null? right:left;
    }
}
```