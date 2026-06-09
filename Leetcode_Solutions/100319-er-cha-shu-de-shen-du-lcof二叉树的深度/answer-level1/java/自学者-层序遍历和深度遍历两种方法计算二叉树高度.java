### 解题思路
* 重点记忆以下程序遍历
* 深度前序遍历在计算高度时性能比程序遍历高

### 代码

```java []
// 方案一、层序遍历 
// 执行用时 :3 ms, 在所有 Java 提交中击败了6.71%的用户
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
    public int maxDepth(TreeNode root) {
        if(null == root) {
            return 0;
        }
        Deque<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);
        int height = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            TreeNode node;
            for(int i = 0; i < size; i++) {
                node = queue.pollFirst();
                if(node.left!=null) {
                     queue.addLast(node.left);
                }
                if(node.right!=null) {
                    queue.addLast(node.right);
                }
            }
            height++;
        }
        return height;
    }
}
```
```java []
// 方案二、前序深度遍历 
// 执行用时 : 0 ms, 在所有 Java 提交中击败了100.00%的用户
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
    public int maxDepth(TreeNode root) {
        if(null == root) {
            return 0;
        }
        if(root.left == null && root.right == null) {
            // 叶子节点，返回高度
            return 1;
        }
        int maxLeft = maxDepth(root.left);
        int maxRight = maxDepth(root.right);
        return Math.max(maxLeft, maxRight) + 1;
    }
}
```