### 解题思路
假设`preorder`与`inorder`的范围分别为`[ps,pe]`,`[is,ie]`
由于`preorder`为前序遍历，所以`preorder[ps]`绝对是整个树的根节点，而由于`inorder`为中序遍历，遵循左子树-根-右子树的规律，所以我们在`inorder`中找到`preorder[ps]`所在的位置`i`,那么：
`inorder[i]`为根，则`inorder`中`i`左边的值构成左子树，`i`右边的值构成右子树。而在`preorder`中，显然`preorder[ps+1]`起右数左子树长度的值构成左子树，剩下的就构成右子树。
根`preorder[ps]`or`inorder[i]`
左子树构成范围：`preorder[ps+1,ps+left]`,`inorder[is,i-1]`
右子树构成范围：`preorder[ps+left+1,pe]`,`inorder[i+1,is]`
根据这个思路，递归求解即可。

### 代码

```java

class Solution {
    
    private int[] preorder;
    private int[] inorder;

    private void build(TreeNode root,int ps,int pe,int is,int ie)
    {
        if(ps>pe||is>ie)
        {
            return;
        }
        root.val=preorder[ps];//根
        if(ps==pe||is==ie)return;
        int i;//根节点在inorder中的位置
        for(i=is;i<=ie;i++)
            if(inorder[i]==preorder[ps])
                break;
        int left=i-is;//左子树长度
        int right=ie-i;//右子树长度
        
        if(ps+1>ps+left)root.left=null;//左子树为空
        else root.left=new TreeNode(-1);//左子树不为空

        if(ps+left+1>pe)root.right=null;//右子树为空
        else root.right=new TreeNode(-1);//右子树不为空

        build(root.left,ps+1,ps+left,is,i-1);//构造左子树
        build(root.right,ps+left+1,pe,i+1,ie);//构造右子树
        
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        if(preorder.length==0||inorder.length==0)return null;
        if(preorder.length!=inorder.length)return null;
        this.preorder=preorder;
        this.inorder=inorder;

        TreeNode root=new TreeNode(-1);
        build(root,0,preorder.length-1,0,inorder.length-1);
        return root;
    }
}
```