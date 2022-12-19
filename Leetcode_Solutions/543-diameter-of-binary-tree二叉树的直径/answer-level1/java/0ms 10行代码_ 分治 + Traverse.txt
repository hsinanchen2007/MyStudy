### 解题思路

downPath 返回每个点往下走的path 最大长度.
二叉树直径即某个node + 左子树向下最大长度 +  右子树向下最大长度,更新即可。

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
    private int ans;
    
    public int diameterOfBinaryTree(TreeNode root) {
        ans = 0;
        downPath(root);
        return ans;
    }
    
    public int downPath(TreeNode node) {
        if(node == null) {
            return 0;
        }
        int left = downPath(node.left);
        int right = downPath(node.right);
        ans = Math.max(ans, left + right);
        return Math.max(left, right) + 1;
    }
}
```