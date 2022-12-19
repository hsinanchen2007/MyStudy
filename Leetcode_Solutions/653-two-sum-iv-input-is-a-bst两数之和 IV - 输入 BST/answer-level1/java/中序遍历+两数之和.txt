### 解题思路
中序遍历+两数之和

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
    public boolean findTarget(TreeNode root, int k) {
        if (root == null) {
            return false;
        }

        Stack<TreeNode> stack = new Stack<>();
        Set<Integer> set = new HashSet<>();
        while (!stack.isEmpty() || root != null) {
            if (root != null) {
                stack.add(root);
                root = root.left;
            } else {
                root = stack.pop();
                if (!set.contains(root.val)) {
                    set.add(k - root.val);
                } else {
                    return true;
                }
                root = root.right;
            }
        }

        return false;
    }
}
```