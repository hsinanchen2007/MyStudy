### 解题思路
此处撰写解题思路

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
      List<List<Integer>> ret = new ArrayList<>();
      if (root == null) {
          return ret;
      }
      List<TreeNode> currentLevel = new ArrayList<>();
      currentLevel.add(root);
      while(!currentLevel.isEmpty()) {
          List<TreeNode> nextLevel = new ArrayList<>();
          List<Integer> currentInt = new ArrayList<>();
          for (TreeNode tree : currentLevel) {
            currentInt.add(tree.val);  
            if (tree.left != null) {
                nextLevel.add(tree.left);
            }
            if (tree.right != null) {
                nextLevel.add(tree.right);
            }
          }
          ret.add(currentInt);
          currentLevel = nextLevel;
      }
      Collections.reverse(ret);
      return ret;
    }


}
```