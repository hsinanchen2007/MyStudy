### 解题思路
1. left = 当前节点左侧返回的最大值
2. right = 当前节点右侧返回的最大值
3. 判断条件： 当前val + left或者val + right为返回值向上递归，但存ans做全局变量，记录以当前节点为顶点的值
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
    int ans = 0;

    public int maxPathSum(TreeNode root) {
        if(root == null) return 0;
        ans = root.val;
        findMax(root);
        return ans;
    }
    
    private int findMax(TreeNode root){
        if(root == null){
            return 0;
        }
        int left = findMax(root.left);
        int right = findMax(root.right);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        int max = Math.max(root.val, Math.max(root.val+left, root.val+right));
        ans = Math.max(ans, Math.max(max, root.val+left+right));
        return max;
    }
}
```