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
    public boolean isValidBST(TreeNode root) {
        Recurse(root);
        return isBST;
    }

    private List<Integer> l = new ArrayList<>();
    private boolean isBST = true;

    private void Recurse(TreeNode root) {
        if (root == null || !isBST) {
            return;
        }
        Recurse(root.left);
        if (l.size() > 0 && l.get(l.size() - 1) >= root.val) {
            isBST = false;
            return;
        }
        this.l.add(root.val);
        Recurse((root.right));
        return;
    }
}
```