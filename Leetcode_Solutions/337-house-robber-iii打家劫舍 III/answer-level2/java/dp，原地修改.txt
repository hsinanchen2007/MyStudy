递归后续遍历二叉树，当遍历置某个节点时，更新该节点的值。使其变为“抢劫以该节点为根的子树所能得到的最大收益”。由递归定义，最后返回根节点的值即可。

实际会从两个选项其中之一得到打劫的最大收益：
1. 抢劫根节点，并抢劫子节点的子节点（孙子节点？）。
2. 不抢劫根节点，并抢劫子节点。

速度100%

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
    public int rob(TreeNode root) {
        if(root==null) return 0;
        int l=0, r=0, ll=0, lr=0, rl=0, rr=0;
        if(root.left!=null) l=rob(root.left);
        if(root.right!=null) r=rob(root.right);
        if(root.left!=null) {
            l = root.left.val;
            if(root.left.left!=null) ll = root.left.left.val;
            if(root.left.right!=null) lr = root.left.right.val;
        }
        if(root.right!=null) {
            r = root.right.val;
            if(root.right.left!=null) rl = root.right.left.val;
            if(root.right.right!=null) rr = root.right.right.val;
        }
        root.val = Math.max(root.val+ll+lr+rl+rr, l+r);
        return root.val;
    }
}
```
