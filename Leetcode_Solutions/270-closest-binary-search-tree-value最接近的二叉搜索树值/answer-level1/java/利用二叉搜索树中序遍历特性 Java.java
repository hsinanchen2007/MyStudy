### 解题思路
对于二叉搜索树而言，其中序遍历所产生的序列将是有序递增的，我们可以根据中序遍历的模板进行一些改造以解答当前题。

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
    public int closestValue(TreeNode root, double target) {
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();
        double min = Math.abs(root.val - target);
        int ans = root.val;
        TreeNode curr = root;
        stack.push(root);
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            if (Math.abs(curr.val - target) < min) {
                min = Math.abs(curr.val - target);
                ans = curr.val;
            }
            curr = curr.right;
        }
        return ans;
    }
}
```