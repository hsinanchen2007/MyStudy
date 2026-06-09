### 解题思路
通过层次遍历解决问题即可

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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        List<TreeNode> levelList = new LinkedList<>();
        if (root == null) {
            return null;
        }
        if (d == 1) {
            TreeNode node = new TreeNode(v);
            node.left = root;
            return node;
        }
        levelList.add(root);
        int levelSize = levelList.size();
        int level = 1;
        while (true) {
            if (level == d-1) {
                for (int i=0;i<levelSize;i++) {
                    TreeNode leftNode = new TreeNode(v);
                    TreeNode rightNode = new TreeNode(v);
                    if (levelList.get(i).left != null) {
                        TreeNode leftTemp = levelList.get(i).left;
                        leftNode.left = leftTemp;
                    } 
                    levelList.get(i).left = leftNode;
                    if (levelList.get(i).right != null) {
                        TreeNode rightTemp = levelList.get(i).right;
                        rightNode.right = rightTemp;
                    }
                    levelList.get(i).right = rightNode;
                }
                break;
            }
            for (int i=0;i<levelSize;i++) {
                TreeNode node = levelList.remove(0);
                if (node.left != null) {
                    levelList.add(node.left);
                }
                if (node.right != null) {
                    levelList.add(node.right);
                }
            }
            level++;
            levelSize = levelList.size();
            if (levelSize == 0) {
                break;
            }
        }
        return root;
    }
}
```