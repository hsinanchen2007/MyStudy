### 解题思路
因为是二叉搜索树，发现用DFS很方便。DFS可以直接用leetcode的模板
类似的有二叉树的中序遍历，一样可以用DFS

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
    public int kthSmallest(TreeNode root, int k) {
        int res = 0;
        if (root == null) {
            return res;
        }
        // DFS
        LinkedList<TreeNode> stack = new LinkedList<>();
        TreeNode curNode = root;
        while (!stack.isEmpty() || curNode != null) {
            while (curNode != null) {
                stack.push(curNode);
                curNode = curNode.left;
            }
            curNode = stack.pop();
            if (--k == 0) {
                res = curNode.val;
                break;
            }
            curNode = curNode.right;
        }
        return res;
    }
}
```