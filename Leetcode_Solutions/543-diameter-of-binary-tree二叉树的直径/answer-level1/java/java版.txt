### 解题思路
二叉树的直径等于路径经过的最多的节点数-1,因为路径长度等于路径经过的节点数-1.
经过的路径最多的节点数也即是左子树的深度+右子树的深度+1(根节点)。

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
    int ans;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        ans=1;
        helper(root);
        return ans-1;
    }
    public int  helper(TreeNode root){
        if(root==null) return 0;
        int L=helper(root.left);//左子树的深度
        int R=helper(root.right);//右子树的深度
        ans=Math.max(ans,L+R+1);//更新直径
        return Math.max(L,R)+1;//求左右子树的深度
    }
}
```