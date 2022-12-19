### 解题思路
递归返回 subtree的 {node数量 和 nodes value sum}
### 代码

```java
class Solution {
   double maxAvg = Double.NEGATIVE_INFINITY;

  public double maximumAverageSubtree(TreeNode root) {
    if (root == null) return maxAvg;

    subtreeInfo(root);

    return maxAvg;
  }

  private TreeInfo subtreeInfo(TreeNode node) {
    if (node == null) return new TreeInfo(0, 0);

    TreeInfo left = subtreeInfo(node.left);
    TreeInfo right = subtreeInfo(node.right);

    int size = left.size + right.size + 1;
    int sum = left.sum + right.sum + node.val;

    maxAvg = Math.max(maxAvg, sum * 1.0 / size);

    return new TreeInfo(size, sum);
  }

  class TreeInfo {
    int size;
    int sum;

    TreeInfo(int size, int sum) {
      this.size = size;
      this.sum = sum;
    }
  }
}
```