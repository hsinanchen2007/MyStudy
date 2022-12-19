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
        LinkedList<String> result = new LinkedList<>();
        recursive(root, "", result);
        return result;
    }

    public void recursive(TreeNode root, String path, LinkedList<String> result) {
        if (root != null) {
            path += String.valueOf(root.val);
            if (root.left == null && root.right == null) {
                result.add(path);
            } else {
                path += "->";
                recursive(root.left, path, result);
                recursive(root.right, path, result);
            }
        }
    }
}
```