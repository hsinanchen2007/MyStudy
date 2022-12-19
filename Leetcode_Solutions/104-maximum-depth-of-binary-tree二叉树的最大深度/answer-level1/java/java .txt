### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.3 MB, 在所有 Java 提交中击败了8.68%的用户

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
    int height = 0;
    public int maxDepth(TreeNode root) {
        if(root == null)
            return 0;
        else{
            height = Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        }
        return height;
    }
}
```