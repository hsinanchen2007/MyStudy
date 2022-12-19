1、注意有可能是负数，所以不能用CurrentSum >Sum之类的return判断
2、注意currentSum = sum之后，也有可能加起来为0的，所以也不能return

```
import java.util.LinkedList;
import java.util.Queue;

/**
 * Definition for a binary tree node.

 */
class Solution {
    private int mCount = 0;

    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            dfs(node, sum, 0);

            if (node.left != null) {
                queue.add(node.left);
            }

            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return mCount;
    }

    private void dfs(TreeNode node, int sum, int currentSum) {
        if (node == null) {
            return;
        }
        currentSum = currentSum + node.val;
        if (sum == currentSum) {
            mCount++;
        }

        dfs(node.left, sum, currentSum);
        dfs(node.right, sum, currentSum);;
    }
}
```
