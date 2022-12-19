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
    public TreeNode increasingBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        LinkedList<TreeNode> treeNodes = new LinkedList<>();
        inOrder(root, treeNodes);
        for (int i = 1; i < treeNodes.size(); i++) {
            TreeNode temp = treeNodes.get(i - 1);
            temp.left = null;
            temp.right = treeNodes.get(i);
        }
        treeNodes.get(treeNodes.size() - 1).right = null;
        return treeNodes.get(0);
    }

    void inOrder(TreeNode root, LinkedList<TreeNode> treeNodes) {
        if (root != null) {
            inOrder(root.left, treeNodes);
            treeNodes.add(root);
            inOrder(root.right, treeNodes);
        }
    }
}
```