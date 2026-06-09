

这道题目代码 很简单
但是理解却花了我不少时间，在b站上也找了讲解视频
[小哥的视频](https://www.bilibili.com/video/av52023556?from=search&seid=4035165195878884959)

经过苦思冥想
写一下在自己的理解
首先简化一下，如何在非搜索的二叉树下搜索递归地一个结点？
1，  root遇到target直接返回
2， 搜索左子树
3， 搜索右子树

递归先只考虑一个结点，
1，如果
在左子树reach到了X或者Y
并且
在右子树reach到了X或者Y
root.left == X && root.right == Y
那么返回root
2，如果只在其中一棵子树上找到了X(Y),那说明X或者Y就是祖先
```
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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        
        if(left!=null && right!=null) return root;
        return (left == null)? right:left;
    }
}
```
