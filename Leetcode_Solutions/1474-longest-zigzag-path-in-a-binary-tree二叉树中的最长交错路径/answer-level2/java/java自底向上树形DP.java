### 解题思路
res[0]表示当前节点下一步向左走带来的最大收益，res[1]表示当前节点下一步向右走带来的最大收益
res[0]=1+left[1] 当前节点下一步向左走带来的最大收益等于左子节点向右走的最大收益+1
res[1]=1+right[0] 当前节点下一步向右走带来的最大收益等于右子节点向左走的最大收益+1

维护一个全局变量maxPath，每次遍历某一节点时，更新它

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
  private int maxPath = 0;

  public int longestZigZag(TreeNode root) {
    dfs(root);
    return maxPath;
  }

  private int[] dfs(TreeNode root) {
    int[] res = new int[2];
    if (root == null) {
      res[0] = -1;
      res[1] = -1;
     return res;
    }
    int[] left = dfs(root.left);
    int[] right = dfs(root.right);
    res[0] = 1 + left[1];
    res[1] = 1 + right[0];
    maxPath = Math.max(maxPath, Math.max(res[0], res[1]));
    return res;
  }
}
```