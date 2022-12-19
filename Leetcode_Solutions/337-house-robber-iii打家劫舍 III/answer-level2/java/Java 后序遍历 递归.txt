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
    /**二叉树的套路
     * 收集左子树的信息
     * 收集右子树的信息
     * 根结点汇总并返回给上其父节点
     */
    public int rob(TreeNode root) {

        if(root == null){
            return 0;
        }
        //res[0] 打劫该节点 res[1]不打劫该点
        int[] res = helper(root);
        return Math.max(res[0], res[1]);
        
    }
    public int[] helper(TreeNode root){
        if(root == null) return new int[]{0, 0};
        int[] res = new int[2];
        int[] resL = helper(root.left);
        int[] resR = helper(root.right);
        res[1] = root.val + resL[0] + resR[0];
        res[0] = Math.max(resL[0], resL[1]) + Math.max(resR[0], resR[1]);
        return res;

    }
}
```