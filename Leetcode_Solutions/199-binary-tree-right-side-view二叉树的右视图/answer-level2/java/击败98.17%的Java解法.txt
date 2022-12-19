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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> nodeValues = new ArrayList<>();
        if (root == null) {
            return nodeValues;
        }
        List<TreeNode> nodes = new ArrayList<>();
        nodes.add(root);
        while(!nodes.isEmpty()) {
            List<TreeNode> nextNodes = new ArrayList<>();
            nodeValues.add(nodes.get(0).val);
            for (int i = 0; i < nodes.size(); ++i) {
                TreeNode treeNode = nodes.get(i);
                if (treeNode.right != null) {
                    nextNodes.add(treeNode.right);
                }
                if (treeNode.left != null) {
                    nextNodes.add(treeNode.left);
                }
            }
            nodes = nextNodes;
        }
        return nodeValues;

    }
}
```