### 解题思路
二叉搜索树的两个性质：
1. 根节点 > 左子树中最大值，根节点 < 右子树中最小值
2. 中序遍历(左->中->右)遍历的结果是递增顺序的
通过上面两个性质我们可以得到：对于二叉搜索树来说，第 1 大的数是最右边的节点，所以：
1. 递归到最右节点，此时 k = 1
2. 接下来的节点 k 不断++
3. 当 找到第 k 个节点时，此时该节点就是我们要找的节点
还是中序遍历的思路，只不过这次是按照：`右 -> 中 -> 左`的思路

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
    Integer targetVal;
    int count;
    public int kthLargest(TreeNode root, int k) {
        count = 0;
        findKthNums(root, k);
        return targetVal;
    }

    private void findKthNums(TreeNode root, int k) {
        if (root == null || targetVal != null) {
            return;
        }
        findKthNums(root.right, k);
        count++;
        if (count == k) {
            targetVal = root.val;
            return ;
        }
        findKthNums(root.left, k);
    }
}
```