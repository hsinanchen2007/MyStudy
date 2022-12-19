### 解题思路
此处撰写解题思路
二叉树左节点小于根节点，右节点大于根节点

时间复杂度：O(n) n为节点的数量
空间复杂度：二叉树的空间复杂度为树的深度，O(h)
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
    public int rangeSumBST(TreeNode root, int L, int R) {
        int count=0;
        if(root==null) return 0;
        if(root.val>=L && root.val<=R)
            return root.val+rangeSumBST(root.left,L,R)+rangeSumBST(root.right,L,R);//返回当前根节点和左右子节点
        if(root.val<L) return rangeSumBST(root.right,L,R);//小于左节点，访问右节点
        
        else return rangeSumBST(root.left,L,R);
    }
}
```