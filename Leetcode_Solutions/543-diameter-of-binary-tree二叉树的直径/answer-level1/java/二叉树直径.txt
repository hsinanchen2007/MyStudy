### 解题思路
求深度的同时更新max,最长路径肯定有且仅有一个最小深度节点。当路径中深度最小的节点是当前节点时，最大路径的节点数为depth(root.left)+depth(root.right)+1,长度为left+right。求出以每个节点为最小深度节点的结果，找到max。

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
    private int max=0;          //记录最长直径
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        depth(root);
        return max;
    }

    public int depth(TreeNode root){
        if(root==null) return 0;
        int left=depth(root.left);        //左子树深度
        int right=depth(root.right);      //右子树深度
        if(left+right>max) max=left+right;  //当路径深度最小的节点是当前节点时，最大路径的节点数为left+right+1,长度为left+right。
        return Math.max(left,right)+1;
    }
}
```