### 解题思路
dfs

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
    int level = 0;

    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        dfs(root, 1);
        return level; 
    }

    public void dfs(TreeNode node, int lv) {
        if(node == null) return;
        if(lv > level) level = lv;
        dfs(node.left, lv+1);
        dfs(node.right, lv+1);
    }
}
```