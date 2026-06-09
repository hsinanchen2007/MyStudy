### 解题思路
分为三种情况：
1 当root.val<L时，因为二叉树为搜索二叉树，所以所有左子树上的节点都小于L，因此左子树和根节点全部修剪掉，然后对右子树进行递归修剪。
2 当root.val>R时，因为二叉树为搜索二叉树，所以所有右子树的节点都大于R,因此右子树和根节点全部修剪掉，然后对左子树进行递归修剪。
3 当L<root.val<R时，此时根节点不变，然后对左右子树进行递归修剪。

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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if(root==null) return null;
        if(root.val<L){//情况1
           root=trimBST(root.right,L,R);
        }else if(root.val>R){//情况2 
            root=trimBST(root.left,L,R);
        }else{//情况3
            root.left= trimBST(root.left,L,R);
            root.right= trimBST(root.right,L,R);
        }
        return root;
    }
}
```