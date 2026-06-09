### 解题思路
用数组记录sum，使其在递归深处改变的值可以反应到上层来。

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
    public TreeNode convertBST(TreeNode root) {
        dfs(root,new int[1]);
        return root;
    }

    private void dfs(TreeNode root,int[] sum){
        if (root == null)
            return;
        dfs(root.right,sum);
        root.val = root.val + sum[0];
        sum[0] = root.val;
        dfs(root.left,sum);
    }
}
```