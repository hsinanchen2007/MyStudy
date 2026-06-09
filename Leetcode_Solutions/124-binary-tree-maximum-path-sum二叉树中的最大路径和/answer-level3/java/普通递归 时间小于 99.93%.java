### 解题思路
递归思路很简单，首先我要返回的是经过该节点最大的一条路径（左或右 不能都选，否则不能选上面的了）
，走左边（root.val + left）最大，还是走右边最大(root.val + right)，还是就返回自己最大(root)。

而最后希望我们找到的是一条连同的路径，那么我们每次都看一下，如果在当前节点连通左右，是否是最大解，记录在 max，
最后返回 max 即可。

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
    int max;

    public int maxPathSum(TreeNode root) {  
        max = root.val;
        findMaxPathSum(root);
        return max;
    }

    public int findMaxPathSum(TreeNode root){
        if(root == null) return 0;
        int left = findMaxPathSum(root.left);
        int right = findMaxPathSum(root.right);
        int res = Math.max(root.val, Math.max(root.val+left,root.val+right));
        max = Math.max(max, Math.max(res, root.val+left+right));
        return res;
    }
}
```