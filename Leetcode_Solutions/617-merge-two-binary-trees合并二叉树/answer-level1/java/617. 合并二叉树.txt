/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/27
 *
 * 解题思路: 在判断的过程中构造新的二叉树 创建一个新的当前节点然后把他的左右节点赋值在 left right 最后返回node
 *
 */
```
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {

    TreeNode new_node = null;
    TreeNode l = null;
    TreeNode r = null;

    if(t1 == null && t2 == null) {
        return new_node;
    }
    else if(t1 == null && t2 != null) {
        new_node = new TreeNode(t2.val);
        l = mergeTrees(null,t2.left);
        r = mergeTrees(null,t2.right);
    }
    else if(t1 != null && t2 == null){
        new_node = new TreeNode(t1.val);
        l = mergeTrees(t1.left,null);
        r = mergeTrees(t1.right,null);
    }
    else {
        new_node = new TreeNode(t1.val + t2.val);
        l = mergeTrees(t1.left,t2.left);
        r = mergeTrees(t1.right,t2.right);
    }

    new_node.left = l;
    new_node.right = r;
    return new_node;
}
```