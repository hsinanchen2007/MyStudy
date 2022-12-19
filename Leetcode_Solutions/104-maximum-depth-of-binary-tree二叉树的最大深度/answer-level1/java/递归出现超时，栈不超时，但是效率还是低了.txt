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
    // 解法一：递归会超时
    // public int maxDepth(TreeNode root) {
    //     if (root == null) {
    //         return 0;
    //     }
    //     return maxDepth(root.left) >= maxDepth(root.right) ? maxDepth(root.left) + 1 : maxDepth(root.right) + 1;
    // }

    // 解法二：栈
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // 利用栈存储二叉树，遍历二叉树，栈所能达到的最大深度就是树的深度
        Stack<TreeNode> stack = new Stack<>();
        int depth = 0;
        int maxDepth = 0;
        TreeNode tmp = null;
        // 只有出栈才能遍历到该元素值
        // 要写后序遍历，否则深度可能比真实深度少，因为后序遍历可以保证根结点不提前释放
        while (root != null || !stack.empty()) {
            if (root != null) {
                stack.push(root);
                depth++;
                if (maxDepth < depth) {
                    maxDepth = depth;
                }
                root = root.left;
            }
            else {
                if (stack.peek().right != null && stack.peek().right != tmp) {
                    root = stack.peek().right;
                }
                else {
                    tmp = stack.pop();
                    depth--;
                    root = null;
                }
            }
        }
        return maxDepth;
    }
}
```