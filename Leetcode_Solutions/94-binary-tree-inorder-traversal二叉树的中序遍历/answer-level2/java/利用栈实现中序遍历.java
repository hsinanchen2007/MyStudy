### 解题思路
利用栈从根节点开始记录树的左节点，直到左节点为null，然后出栈，并记录出栈节点的值，然后对出栈节点右子树重复执行前面的过程。

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
    public List<Integer> inorderTraversal(TreeNode root) {
         Stack<TreeNode> stack = new Stack<>();
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        TreeNode tmp = root;
        while (tmp != null) {
            stack.push(tmp);
            tmp = tmp.left;
        }
        while (!stack.empty()) {
            tmp = stack.pop();
            result.add(tmp.val);
            tmp = tmp.right;
            while (tmp != null) {
                stack.push(tmp);
                tmp = tmp.left;
            }
        }

        return result;
    }
}
```