### 解题思路
    此题考查满二叉树和完全二叉树的性质，请认真掌握。

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
    public int countNodes(TreeNode root) {
        //如何判断完全二叉树的高度。先求左右子树的高度，如果高度相等，则说明左子树一定是满二叉树，进一步判断右子树的节点个数即可。如果不等则说明右子树是深度小于左子树的满二叉树，然后进一步判断左子树。
        if(root==null)
            return 0;
        int ld=getDepth(root.left);
        int rd=getDepth(root.right);
        if(ld==rd)  //两遍子树高度相等，左子树是满二叉树
            return (1<<ld)+countNodes(root.right);  //递归去求右子树就可以了
        else 
            return (1<<rd)+countNodes(root.left);
    }

    private int getDepth(TreeNode root)
    {
        if(root==null)
            return 0;
        return 1+Math.max(getDepth(root.left),getDepth(root.right));
    }
}
```