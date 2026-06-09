看题意顺序明显是先序遍历，二叉树的深度遍历本来只用递，没有用到归，所以我判定把归利用起来，肯定是能够解题的。
一句话思路就是先序遍历，如果走到最左边，则把此节点指针返回到有右节点的位置，把该右节点挪到最左边节点的左边，继续递归即可。
需要注意的是，一定要注意将右节点接在左叶子节点之后记得把右节点清空。
还有如果将nullLeftNode左叶子节点指针改为全局变量会省事儿很多，不用归，直接递，但是考虑到原地展开，就没有用到外部存储空间。
本解法时间复杂度O(n)，因为每一个节点都遍历了一遍；空间复杂度O(1),只有两个临时节点。
我想拿那个精选评论的奖励金币，换个周边小礼物，希望有收获的朋友点个赞，给个评论，谢谢！
```
class Solution {
    public void flatten(TreeNode root) {
        if(root==null){
            return ;
        }
        //先将二叉树转换成左展开链表
        flattenHelper(root);
        //再将左展开转换成右展开链表
        TreeNode tempNode =root;
        while(tempNode.left!=null){
            tempNode.right = tempNode.left;
            tempNode.left = null;
            tempNode= tempNode.right;
        }
    }
    private TreeNode flattenHelper(TreeNode root){
        //如果左右节点都为空则返回当前节点，也就是最后的左边的节点；
        if(root.left==null&&root.right==null){
            return root;
        }
        //如果左为空右不为空，则把右边的移到左边，然后继续递归左边的；
        if(root.left==null&&root.right!=null){
            root.left=root.right;
            root.right=null;
            return flattenHelper(root.left);
        }
        //如果左不为空右为空则直接递归左边的；
        if(root.left!=null&&root.right==null){
            return flattenHelper(root.left);
        }
        //如果左右都不为空则把左边归过来的末节点的左节点赋值为当前节点的右节点，然后继续递归；
            TreeNode nullLeftNode= flattenHelper(root.left);
            nullLeftNode.left = root.right;
            root.right=null;
            return flattenHelper(nullLeftNode.left);
    }
}
```
