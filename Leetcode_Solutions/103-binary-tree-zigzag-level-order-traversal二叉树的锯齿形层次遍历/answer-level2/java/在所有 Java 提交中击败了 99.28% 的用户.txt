### 解题思路
递归

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
    private List<List<Integer>> ans = new ArrayList<>();
    
    private void helper(TreeNode node, int level) {
        if (ans.size() == level)
            ans.add(new ArrayList<>());
        if (level % 2 == 0) {
            ans.get(level).add(node.val);
        } else {
            ans.get(level).add(0, node.val);
        }
        if (node.left != null)
            helper(node.left, level + 1);
        if (node.right != null)
            helper(node.right, level + 1);
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return ans;
        helper(root, 0);
        return ans;
    }
}
```