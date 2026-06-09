/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 *
 * 解题思路: 利用二叉搜索数的性质进行遍历 并在过程中构造新的二叉树 构造是时
 *  当前节点小于L 将右子树进行递归加入
 *  当前节点大于R 将左子树进行递归加入
 *  当前节点在L R 之间 将左右子树递归加如 当前的节点的左右子树
 *
 *  trimBST : 返回根据 L R的过滤后的二叉树
 *
 */
```
public TreeNode trimBST(TreeNode root, int L, int R) {

    if(root == null) return null;

    TreeNode res = null;

    if(root.val < L){
        res = trimBST(root.right , L ,R);
    }else if(root.val > R){
        res = trimBST(root.left , L ,R);
    }else{
        res = new TreeNode(root.val);
        TreeNode l = trimBST(root.left , L ,R);
        TreeNode r = trimBST(root.right , L ,R);
        res.left = l;
        res.right = r;
    }

    return res;
}
```