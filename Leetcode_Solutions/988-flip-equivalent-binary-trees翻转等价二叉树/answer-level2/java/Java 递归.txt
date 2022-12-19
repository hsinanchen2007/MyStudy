### 解题思路
首先我们需要检查两棵二叉树中同一位置的两个节点的值是否相等，若相等，再判断两者的左右子树是否相等或者是否可以通过翻转而相等。如此递归下去即可。

### 代码

```java

class Solution {
    
    //判断两个节点是否相同
    boolean helper(TreeNode r1,TreeNode r2){
        if((r1!=null&&r2!=null&&r1.val==r2.val)||(r1==null&&r2==null))return true;
        else 
        return false;
    }
    
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        //判断根节点是否相同
        if(!helper(root1,root2))return false;
        if(root1==null)return true;
        //判断左右子树是否相同或者可以通过翻转相同
        boolean res=(helper(root1.left,root2.left)||helper(root1.left,root2.right))&&
            (helper(root1.right,root2.left)||helper(root1.right,root2.right));
        if(!res)return res;
        //判断左右子树的左右子树是否满足条件
        //每个子树要判断两次是因为我们并不知道究竟是否需要经过翻转才能与另外一个子树相同
        return (flipEquiv(root1.left,root2.left)||flipEquiv(root1.left,root2.right))&&
            (flipEquiv(root1.right,root2.left)||flipEquiv(root1.right,root2.right));
    }
}
```