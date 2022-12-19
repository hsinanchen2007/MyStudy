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
    public List<Integer> preorderTraversal(TreeNode root) {
      List<Integer> values = new ArrayList<>();
      preorderTraversal(root, values);
      return values;
    }

    private void preorderTraversal(TreeNode root, List<Integer> values) {
        if (root == null) {
            return;
        } 
        values.add(root.val);
        preorderTraversal(root.left, values);
        preorderTraversal(root.right, values); 

    }
}
```