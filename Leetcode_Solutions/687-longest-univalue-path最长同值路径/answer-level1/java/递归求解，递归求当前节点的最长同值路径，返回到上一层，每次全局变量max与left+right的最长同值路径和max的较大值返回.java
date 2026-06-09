### 解题思路
这题采用递归方式，分别求左右子树的最长同值路径，如果根节点和他们相同，左右子树最长同值路径+1；如果不同，对应的最长同值路径就要归0，为什么要归0呢，加入左孩子节点的父节点与左孩子节点不同的时候，左子树最长同值就断掉了，父节点的左子树最长同值路径这时候就是0，右子树同理。然后每次都获取全局的max和left+right的更大值，更新到max中，将left和right的更大值递归返回到上一层。

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
    private int maxPath = 0;

    public int longestUnivaluePath(TreeNode root) {
        if (root == null){
            return 0;
        }
        helper(root);
        return maxPath;
    }

    /**
     * 递归获取当前root为根节点的最长同值路径
     * @param root root
     * @return 最长同值路径边的个数
     */
    private int helper(TreeNode root){
        if (root == null){
            return 0;
        }
        int left = helper(root.left);// 左子树当前同值数
        int right = helper(root.right);// 右子树当前同值数
        if (root.left != null && root.val == root.left.val){
            left++;// 如果root和left相同，左子树当前同值数+1
        }else {
            left = 0;// 不同的话，最长同值数在这里就断开了，左子树当前同值数归0
        }
        if (root.right != null && root.val == root.right.val){
            right++;// 如果root和right相同，右子树当前同值数+1
        }else {
            right = 0;// 不同的话，最长同值数在这里就断开了，右子树当前同值数归0
        }
        // 当前节点往父节点走的最大路径节点数，因为左右子树只能留下一个，所以取较大的那一个
        int curPath = Math.max(left,right);
        // 经过当前节点的最长同值路径
        maxPath = Math.max(maxPath,left + right);// 同值路径可以经过root，也可以不经过root，所以左右直接相加
        return curPath;// 返回root的当前最长同值路径
    }
}
```