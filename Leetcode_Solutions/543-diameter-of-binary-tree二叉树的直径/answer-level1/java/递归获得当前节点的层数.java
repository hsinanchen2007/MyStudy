res 作为类内部的全局变量，时刻保留当前最大的二叉树直径。

```java []
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
    
    //全局变量保留最大的值
    private int res =0;
    public int diameterOfBinaryTree(TreeNode root) {
        maxDiameter(root);
        return res;
    }

    public int maxDiameter(TreeNode root)
    {
        if (root == null){
            return 0;
        }
      //递归左右子树
        int r = maxDiameter(root.right);
        int l = maxDiameter(root.left);
        //更新二叉树直径
        res = Math.max(res,l+r);
        //返回的是该节点的层数
        return Math.max(l,r)+1;
    }
}
```
