![image.png](https://pic.leetcode-cn.com/48d129edcbe24ed700411ed70210a69afc48d51af7d4f6ba992f109c4b6146d3-image.png)
```
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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (root==null) return null;
        if (root.val<L) //如果值较小，要考虑其右侧节点
        	return trimBST(root.right,L,R);
        
        if (root.val>R)//如果值较大，要考虑其左侧节点
        	return trimBST(root.left,L,R);
        
        root.left=trimBST(root.left,L,R);
        root.right=trimBST(root.right,L,R);
        
        return root;
    }
}
```
