### 解题思路
这类题目后序遍历就得了，利用树形dp套路

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
    public int maxAll = Integer.MIN_VALUE;
    public int longestUnivaluePath(TreeNode root){
        if(root == null)
            return 0;
        pos(root);
        return maxAll;
    }

    public int pos(TreeNode root){
       if(root == null)
            return  0;
        int l = pos(root.left);
        int r = pos(root.right);
        int max = Integer.MIN_VALUE;
        int maxL = Integer.MIN_VALUE;
        int maxR = Integer.MIN_VALUE;
        if(root.left != null && root.val == root.left.val){
            max = l + 1;
            maxL = l + 1;
        }
        if(root.right != null && root.val == root.right.val){
            max = r + 1;
            maxR = r + 1;
        }
        if(root.left != null && root.right != null && root.left.val == root.val && root.right.val == root.val)
            max = l+r+1;
        if(max == Integer.MIN_VALUE)
            max = 1;
        maxAll = Math.max(max-1, maxAll);
        return Math.max(Math.max(maxL, maxR), 1);
    }
}
```