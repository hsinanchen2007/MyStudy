### 解题思路
记在这里，以后回来看的时候注意递归和迭代法两种思路

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        while (!s.empty()) {
            TreeNode popNode = s.pop();
            result.add(popNode.val);
            if (popNode.right != null) {
                s.push(popNode.right);
            }
            if (popNode.left != null) {
                s.push(popNode.left);
            }
        }
        return result;
    }
}
```