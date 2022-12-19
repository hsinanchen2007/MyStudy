![搜狗截图20191109132944.png](https://pic.leetcode-cn.com/dd1d6f7e9f493e2a35d7f5990c8ca1136a1119bd9addc7490859cc57588d2b68-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20191109132944.png)
```
/*
根据题意展成的链表都是在右子树，而且是按先序遍历的顺序连接下去。
所以自然按照先序遍历，将左右子树互换顺序，而此时要按先序遍历，
所以dfs(root.right)(因为左右子树换了顺序)，
然后换完之后的左子树要接在右子树的最后一个节点的right上，
所以要返回此时右子树的最后一个节点记为rn,返回后将rn.right = root.left，
再处理左子树，并把左子树的最后一个结点也返回。
*/
class Solution {
    public void flatten(TreeNode root) {
        if (root == null) return ;
        dfs(root);
    }
    TreeNode dfs(TreeNode root){
        if(root.left == null && root.right == null) return root;
        if(root.left == null) //左边为空，直接遍历右子树，并把右子树最后一个结点返回
            return dfs(root.right);
        //左边不为null,那么左右子树互换
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        TreeNode rn = dfs(root.right);//按照先跟遍历（先左后右）,此时左右子树互换了，所以遍历right
        //rn为此时右子树的最后一个结点，若此时root的left为空，那么不用将空子树接入，直接返回rn
        if(root.left == null) return rn;
        rn.right = root.left;//若不为空，将左子树接入右子树最后一个结点(rn)的right
        TreeNode ln = dfs(root.left);//遍历完左子树后把左子树最后一个结点返回
        root.left = null;//记得把root的left置为null（因为展成的链表左子树都为空）
        return ln;  //再把ln返回，作为root这棵树的最后一个结点供root的兄弟结点接入成链
    }
    
}
```
