### 解题思路
DFS递归遍历树,如遇p或者q,返回1,其余返回0.结果(返回值)向上pop up,当第一次遇到2的返回值时,记下节点为结果!Done

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

    private TreeNode res = null;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        recursiveSearch(root, p, q);
        return res;
    }

    private int recursiveSearch(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return 0;
        int left = recursiveSearch(root.left, p, q);
        int right = recursiveSearch(root.right, p, q);
        int mid = root == p || root == q ? 1 : 0;
        if (left + right + mid >= 2 && res == null) res = root;
        return left + right + mid;
    }
}
```