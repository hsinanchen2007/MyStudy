### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
39.5 MB
, 在所有 Java 提交中击败了
100.00%
的用户
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
    private int res;
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        res = 0;
        int left = dfs(root.left) + 1;
        int right = dfs(root.right) + 1;
        res = Math.max(left, right);
        return res;
        
    }
    private int dfs(TreeNode root){
        if (root == null) return 0;
        int tmp = 0;
        int left = dfs(root.left) + 1;
        int right = dfs(root.right) + 1;
        res = Math.max(left, right);
        return res;        
    }
}
```