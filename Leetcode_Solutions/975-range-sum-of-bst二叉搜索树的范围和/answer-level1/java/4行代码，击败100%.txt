### 解题思路
我们对树进行深度优先搜索，对于当前节点 node，如果 node.val 小于等于 L，那么只需要继续搜索它的右子树；如果 node.val 大于等于 R，那么只需要继续搜索它的左子树；如果 node.val 在区间 (L, R) 中，则需要搜索它的所有子树。

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
    public int rangeSumBST(TreeNode root, int L, int R) {
          
          if(root == null) return 0;
          if(root.val >= L && root.val <= R) return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
          else if(root.val < L) return rangeSumBST(root.right, L, R);
          else return rangeSumBST(root.left, L, R);
    }
}
```