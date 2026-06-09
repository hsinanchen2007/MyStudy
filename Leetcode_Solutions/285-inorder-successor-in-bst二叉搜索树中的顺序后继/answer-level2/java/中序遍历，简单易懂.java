### 解题思路
中序遍历，找到目标后，再多找一步即可

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
    public List<TreeNode> res = new ArrayList<>();
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        helper(root, p);
        return res.size() == 2 ? res.get(1) : null;
    }
    public void helper(TreeNode root, TreeNode p) {
        if (root == null) {
            return;
        }
        helper(root.left, p);
        if (root.val == p.val) {
            res.add(root);
        } else if (res.size() == 1) {
            res.add(root);
            return;
        }
        helper(root.right, p);
    }
}
```