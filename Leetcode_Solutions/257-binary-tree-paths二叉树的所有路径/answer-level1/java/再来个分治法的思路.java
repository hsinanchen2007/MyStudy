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
    public List<String> binaryTreePaths(TreeNode root) {
        if(root == null) {
            return new ArrayList<>();
        }

        if(root.left == null && root.right == null) {
            List<String> results = new ArrayList<>();
            results.add(root.val + "");
            return results;
        }

        List<String> left = binaryTreePaths(root.left);
        List<String> right = binaryTreePaths(root.right);

        List<String> results = new ArrayList<>();
        for (String s : left) {
            results.add(root.val + "->" + s);
        }

        for (String s : right) {
            results.add(root.val + "->" + s);
        }
        
        return results;
    }
}
```