### 解题思路
1、递归
递归相当简单.

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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left)+1, maxDepth(root.right)+1);
    }
}
```

2、迭代
使用队列，返回最后迭代的深度

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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int depth=0;
        Queue<TreeNode> s = new LinkedList<>();
        s.add(root);
        while (!s.isEmpty()) {
            depth++;
            int size = s.size();
            for (int i=0; i<size; i++) {
                TreeNode node = s.remove();
                if (node.left != null) {
                    s.add(node.left);
                }
                if (node.right != null) {
                    s.add(node.right);
                }
            }

        }
        return depth;
    }
}
```