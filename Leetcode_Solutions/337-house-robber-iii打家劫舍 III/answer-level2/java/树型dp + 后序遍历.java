### 解题思路
参考labudong思路

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
    public int rob(TreeNode root) {
        //树型dp
        int[] rootMax = robBinaryTree(root);
        
        return Math.max(rootMax[0], rootMax[1]);
    }

    //抢劫
    private int[]  robBinaryTree(TreeNode root)
    {
        //根节点是null
        if (root == null) {
            return new int[]{0, 0};
        }

        //左子树
        int[] left = robBinaryTree(root.left);

        //右子树
        int[] right = robBinaryTree(root.right);

        //选中跟节点,不选择左右节点的最大值
        int selectRoot = root.val + left[0] + right[0];

        //不选中跟节点的最大值
        int noSelectRoot = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);

        return new int[] {noSelectRoot, selectRoot};
    }

}
```