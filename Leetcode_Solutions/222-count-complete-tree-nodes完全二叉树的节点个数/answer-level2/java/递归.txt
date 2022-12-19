### 解题思路
getHeight     递归求出树的高度
getLevelNode  获取该层级的节点

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
    public int countNodes(TreeNode root) {
        int height = getHeight(root);
        List<TreeNode> result = new ArrayList<>();
        getLevelNode(root, height, result);
        return (int) (Math.pow(2, height - 1) - 1 + result.size());
    }
    int getHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    void getLevelNode(TreeNode root, int level, List<TreeNode> result) {
        if (root == null) {
            return;
        }

        if (level == 1) {
            result.add(root);
        } else {
            getLevelNode(root.left, level - 1, result);
            getLevelNode(root.right, level - 1, result);
        }
    }
}
```