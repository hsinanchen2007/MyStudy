### 解题思路
此处撰写解题思路

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
    public int rob(TreeNode root) {
        if(root == null) return 0;
        int[] res = dfs(root);
        return Math.max(res[0],res[1]);
    }
    
    private int[] dfs(TreeNode root){
        if(root == null) return new int[]{0,0};
        //我先拿到左右儿子的结果
        int[] left = dfs(root.left);
        int[] right = dfs(root.right);
        //0代表偷，代表不偷
        int[] res = new int[2];
        //如果当前节点偷，那么儿子就都不能偷
        res[0] = left[1] + right[1] + root.val;
        //如果当前节点不偷，那么儿子可以偷，也可以不偷
        res[1] = Math.max(left[0],left[1]) + Math.max(right[0],right[1]);
        return res;
    }
}
```