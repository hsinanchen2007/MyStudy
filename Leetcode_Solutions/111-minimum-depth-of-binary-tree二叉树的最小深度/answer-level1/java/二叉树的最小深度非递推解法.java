### 解题思路
此处撰写解题思路
 遇到左右子节点为null时直接返回结果
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
        if (root == null)
            return 0;
        int depths = 1;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int count = queue.size();
            while (count-- > 0) {
                TreeNode node = queue.poll();
                if (node.left == null &&  node.right == null)
                  return depths;
                if(node.left != null) {
                    queue.add(node.left);
                }
                 if(node.right != null) {
                    queue.add(node.right);
                }
            }
            depths++;
        }
        return depths;
    }
}
```