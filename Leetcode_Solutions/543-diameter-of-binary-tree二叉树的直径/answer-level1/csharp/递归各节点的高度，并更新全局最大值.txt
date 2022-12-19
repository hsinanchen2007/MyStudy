### 解题思路

- 记以某一节点**p**为根节点的子树的直径为d，它的左子树的高度为hLeft，右子树的高度为hRight，若无对应子树，则对应子树高度为0；
- 节点**p**的高度可以这样求得：取左右子树高度中的较大值，再加1（如果两边子树都为null，则不加1）；这个加1表示较高的子树的根节点与**p**之间有一条边，所以加到高度上，作为**p**的高度；
- 所以以p为最高点的路径的最大值可以这样求出，先求出左右子树的高度和，若左子树不为null，则再+1；右子树不为null，则再+1；
- 从根节点开始调用求路径最大值的子方法，过程中不断更新全局最大值


### 代码

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
        private int maxValue;
        public int DiameterOfBinaryTree(TreeNode root)
        {
            maxValue = 0;
            DepthOfBinaryTreeNode(root);
            return maxValue;
        }

        public int DepthOfBinaryTreeNode(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }
            int left = DepthOfBinaryTreeNode(node.left);
            int right = DepthOfBinaryTreeNode(node.right);
            int depthSum = left + right;
            int leftDepth = left;
            int rightDepth = right;
            if (node.left != null)
            {
                depthSum++;
                leftDepth++;
            }
            if (node.right != null)
            {
                depthSum++;
                rightDepth++;
            }
            if (maxValue < depthSum)
            {
                maxValue = depthSum;
            }
            return leftDepth > rightDepth ? leftDepth : rightDepth;
        }
}
```