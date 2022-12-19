根据前序和中序遍历序列构造二叉树是数据结构中很常见的问题；
我的方法是找出前序序列preorder的第一个数，这就是整棵树的根节点，并且这个数将中序序列inorder分为左子树的中序序列和右子树的中序序列，把这作为递归中的inorder；
递归中的preorder怎么找？preorder数组的排列是`[根节点的值,左子树的前序序列,右子树的前序序列]`，因此只要取出左右子树的前序序列作为递归参数传下去就行；
这个分解的位置就是根节点值在inorder中位置；
举个例子：
第一次运行分割的结果：
preorder = [3,  9,  20,15,7]
inorder = [9,  3,  15,20,7]
第一次递归调用：
root.left = buildTree([9],[9])
root.right = buildTree([20,15,7],[15,20,7])
后续同理。。。
```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length==0) return null;
        int val = preorder[0], i=0;
        TreeNode node = new TreeNode(val);
        while(inorder[i]!=val) i++;
        node.left = buildTree(Arrays.copyOfRange(preorder,1,i+1),Arrays.copyOfRange(inorder,0,i));
        node.right = buildTree(Arrays.copyOfRange(preorder,i+1,preorder.length),Arrays.copyOfRange(inorder,i+1,inorder.length));
        return node;
    }
}
```