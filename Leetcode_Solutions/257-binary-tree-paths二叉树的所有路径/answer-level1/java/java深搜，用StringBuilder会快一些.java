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
    private List<String> res = new ArrayList<String>();
    public List<String> binaryTreePaths(TreeNode root) {
        backTracking(root, new StringBuilder());
        return res;
    }

    private void backTracking(TreeNode root, StringBuilder prefix) {
        if (root == null) return ;
        if (root.left == null && root.right == null) {
            int len = String.valueOf(root.val).length();
            prefix.append(root.val);
            res.add(prefix.toString());
            prefix.delete(prefix.length() - len, prefix.length());
            return ;
        }
        int len = String.valueOf(root.val).length();
        prefix.append(root.val);
        prefix.append("->");
        backTracking(root.left, prefix);
        backTracking(root.right, prefix);
        prefix.delete(prefix.length() - len - 2, prefix.length());

    }
}
```