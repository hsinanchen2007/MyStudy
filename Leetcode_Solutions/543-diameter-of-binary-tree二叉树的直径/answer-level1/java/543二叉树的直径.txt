### 解题思路
此处撰写解题思路
递归遍历二叉树
首先设置全局变量res存储以当前节点为根的最大直径
当前节点的最大直径= max(res, 左子树的深度+右子树的深度+1)；
树的深度 = max(左子树深度,右子树深度) + 1；
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
    int res = 1;
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return res-1;

    }

    public int depth(TreeNode node){
        if(node==null){
            return 0;
        }
        int L = depth(node.left);
        int R = depth(node.right);
        res = Math.max(res,L+R+1);
        return Math.max(L,R)+1;
    }
}
```