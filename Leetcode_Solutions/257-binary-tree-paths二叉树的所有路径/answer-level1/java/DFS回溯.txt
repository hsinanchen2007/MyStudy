### 解题思路
DFS回溯

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
        List<String> res = new ArrayList<>();
        if (root == null) {
            return res;
        }

        List<String> subsets = new ArrayList<>();
        subsets.add(root.val + "");
        dfs(root, subsets, res);
        return res;
    }

    private void dfs(TreeNode root, List<String> subsets, List<String> res) {
        if (root != null && root.left == null && root.right == null) {
            String path = String.join("->", subsets);
            res.add(path);
        }

        if (root.left != null) {
            subsets.add(root.left.val + "");
            dfs(root.left, subsets, res);
            subsets.remove(subsets.size() - 1);
        }

        if (root.right != null) {
            subsets.add(root.right.val + "");
            dfs(root.right, subsets, res);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```