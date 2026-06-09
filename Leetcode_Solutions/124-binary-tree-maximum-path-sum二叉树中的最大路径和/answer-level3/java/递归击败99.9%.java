### 解题思路
看题意第一印象就是树形DP，每个节点的左右子树都给这个节点返回每个子树的最大路径和，这样我们就获得了三个数，左子树的最大路径和A，右子树的最大路径和B，和节点的节点值N。这个节点要返回给父节点的值就只有A+N,B+N,N中的最大值max，这样我们就解决了递归的basecase，同时在每次递归中要实时更新整棵树的最大路径和，这个最大路径和可以是max,同时也有可能是A+B+N,每次递归时，根据这两个值更新最大路径和，递归完，结果就出来了。

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
    int ans = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if(root == null){
            return 0;
        }
        process(root);
        return ans;
    }

    public int process(TreeNode node){
        if(node == null){
            return 0;
        }
        int L = process(node.left);
        int R = process(node.right);
        int maxn = Math.max(Math.max(L + node.val, R + node.val), node.val);
        int newAns = Math.max(maxn, L + R + node.val);
        ans = Math.max(ans, newAns);
        return maxn;
    }
}
```