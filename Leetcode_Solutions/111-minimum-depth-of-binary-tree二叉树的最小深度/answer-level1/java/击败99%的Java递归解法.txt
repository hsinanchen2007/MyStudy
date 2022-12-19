此题和二叉树最大深度不同，需要注意递归过程中的陷阱，因为是计算根节点到叶子节点的深度，所以最终一定要是在叶子节点上停止递归。分两种情况讨论：
1. 左子节点和右子节点均不为null，则可以放心大胆地取左右子树的最小深度，然后加1
2. 左右子树有null的存在，则此时需要取左右子树最大深度，然后加1.因为叶子节点一定只会出现在更大深度的那边。（如果都为null，那就是已经到达叶子节点了，直接返回1）
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
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left != null && root.right != null) {
            return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
        }
        else {
            return Math.max(minDepth(root.left), minDepth(root.right)) + 1;
        }
    }
}
```
