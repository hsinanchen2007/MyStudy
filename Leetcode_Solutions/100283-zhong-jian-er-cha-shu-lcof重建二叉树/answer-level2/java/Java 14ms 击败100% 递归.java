

```java
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder == null || preorder.length==0)
            return null;
        return core(preorder, inorder, 0, preorder.length-1, 0, inorder.length-1);
    }
     
    //核心:操作范围
    //递归函数逻辑: 在当前操作范围[preL,preR],[inL,inR]上找出根节点的值, 创建根节点(当前条件); 
    //然后找出左子树的操作范围,让根节点连接左子树的根; 找出右子树的操作范围, 让根节点连接右子树的根(新条件新递归)
    private TreeNode core(int[] preorder, int[] inorder, int preL, int preR, int inL, int inR){
        //base case
        if(preL>preR)
            return null;
        //创建根节点
        TreeNode root = new TreeNode(preorder[preL]);
        //记录左子树的长度
        int left = 0 ;
        for(int i=inL; i<=inR; i++){
            if(inorder[i] == preorder[preL])
                break;
            left++;
        }
        //处理左子树
        root.left = core(preorder, inorder, preL+1, preL+left, inL, inL+left-1);
        //处理右子树
        root.right = core(preorder, inorder, preL+left+1, preR, inL+left+1, inR);
        //返回根节点
        return root;
    }
}
```