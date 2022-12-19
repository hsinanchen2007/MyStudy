### 递归
题目要求返回BST被修剪后的根结点，那么我们从根结点开始修剪。
如果根结点太小，根结点的左子树的所有结点只会更小，说明根结点及其左子树都应该剪掉，因此直接返回右子树的修剪结果。
如果根结点太大，根结点的右子树的所有结点只会更大，说明根结点及其右子树都应该剪掉，因此直接返回左子树的修剪结果。
如果根结点没问题，则递归地修剪左子结点和右子结点。
如果结点为空，说明无需修剪，直接返回空即可。
左右子结点都修剪完后，返回自身。

代码：
```java
class Solution {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if(root == null)    return null;
        if(root.val < L)    return trimBST(root.right, L, R);
        if(root.val > R)    return trimBST(root.left, L, R);
        root.left = trimBST(root.left, L, R);
        root.right = trimBST(root.right, L, R);
        return root;
    }
}
```