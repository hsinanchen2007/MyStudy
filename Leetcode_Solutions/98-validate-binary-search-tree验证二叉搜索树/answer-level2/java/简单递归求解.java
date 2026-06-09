### 解题思路
递归，利用isValidBST，逻辑简单
时间、空间复杂度都是  O(n)

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
    private Integer last;
    public boolean isValidBST(TreeNode root) {
      if(root == null)   return true;
      if(!isValidBST(root.left) || (last != null && root.val <= last))  return false;
      last = root.val;
      if(!isValidBST(root.right))  return false;
      return true;
    }
}
```