关于二叉树的递归，切入点是考虑对每个节点执行怎样同样的操作。
该题的思路为，每层循环都返回以`root`为根的子树中前序遍历的最后一个节点。
对于每层递归的节点`root`，获得该节点左子树前序遍历的最后一个节点`mleft`，`mleft`的右指针指向`root.right`，然后将`root`节点的左节点变成右节点，最后返回以`root`为根的子树的前序遍历的最后一个节点（如果有右子树，那就是右子树前序遍历最后一个节点`mright`，如果没有那么就是左子树前序遍历最后一个节点`mleft`）
还有一些细节需要考虑，比如如果`root`没有左、右子树会怎么样，这些在代码中具体展出。
```java
class Solution {
    public void flatten(TreeNode root) {
        core(root);
    }
    public TreeNode core(TreeNode root){
        if(root==null)
            return null;
        if(root.right==null&&root.left==null)
            return root;
        TreeNode rootR=root.right;
        TreeNode mleft=core(root.left);
        TreeNode mright=core(root.right);
        if(root.left!=null)
            root.right=root.left;
        root.left=null;
        if(mright==null)
            return mleft;
        else{
            if(mleft!=null)
                mleft.right=rootR;
            return mright;
        }
    }
}
```
