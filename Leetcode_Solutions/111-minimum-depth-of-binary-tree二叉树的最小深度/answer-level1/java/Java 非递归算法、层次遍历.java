### 解题思路
思路较为简单, 层次遍历的代码, 如果遇到的节点左右子节点都为 null, 那么就跳出循环. 因为是层次遍历, 肯定是最小的深度.

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
    public int minDepth(TreeNode root) {
        int level = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        if (root == null) return level;
        queue.add(root);
        here:
        while(queue.size() > 0) {
            int size = queue.size();
            level++;
            for(int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node.left == null && node.right == null) {
                    break here;
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
        return level;
    }
}
```