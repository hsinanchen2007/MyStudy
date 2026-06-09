
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
    public int maxDepth(TreeNode root) {
        // 递归方式
        return maxDepth_recursion(root);

        // 先序遍历
        //return maxDepth_BFS(root);
    }
    // 递归方式
  private int maxDepth_recursion(TreeNode root) {
    if (root == null) {
      return 0;
    }
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
  }

  // BFS
  private int maxDepth_BFS(TreeNode root) {
    if (root == null) {
      return 0;
    }
    LinkedList<TreeNode> linkedList = new LinkedList<>();
    linkedList.add(root);
    int depth = 0;
    while (!linkedList.isEmpty()) {
      depth++;
      int size = linkedList.size();
      for (int i = 0; i < size; i++) {
        TreeNode cur = linkedList.remove();
        if (cur.left != null) {
          linkedList.add(cur.left);
        }
        if (cur.right != null) {
          linkedList.add(cur.right);
        }
      }
    }
    return depth;
  }
}
```

> 可看本人博客[天天説](https://tiantianshuo.github.io/2020/02/06/leetcode/104/)