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
    List<TreeNode> list = new ArrayList<>();

    public void flatten(TreeNode root) {
        frontShow(root);
        makeTree();
    }

    private void makeTree() {

        for (int i = 0; i < list.size() - 1; i++) {
            TreeNode treeNode = list.get(i);
            treeNode.right = list.get(i + 1);
            treeNode.left = null;
        }
    }

    private void frontShow(TreeNode root) {
        if (root == null) {
            return;
        }
        list.add(root);
        frontShow(root.left);
        frontShow(root.right);
    }
}
```