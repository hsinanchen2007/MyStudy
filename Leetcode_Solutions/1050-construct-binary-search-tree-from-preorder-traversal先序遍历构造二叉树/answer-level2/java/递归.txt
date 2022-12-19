### 解题思路
1、左节点小于父节点
2、右节点大于父节点，并小于父节点的父节点
据此递归

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
    int index=0;

    /**
     * 在题目给的规则上再加一个，右节点不可大于父节点的父节点值，据此递归
     * @param preorder
     * @return
     */
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root=new TreeNode(preorder[index++]);
        build(root,preorder,Integer.MAX_VALUE);
        return root;
    }

    private void build(TreeNode root,int[] preorder,int maxNum) {
        if(index<preorder.length&&preorder[index]<root.val){
            TreeNode left=new TreeNode(preorder[index++]);
            root.left=left;
            build(left,preorder,root.val);
        }
        if(index<preorder.length&&preorder[index]>root.val&&preorder[index]<maxNum){
            TreeNode right=new TreeNode(preorder[index++]);
            root.right=right;
            build(right,preorder,maxNum);
        }
    }
}
```