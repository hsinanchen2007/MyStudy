
思路：由于不知道p,q在二叉树中的位置，只能分别取遍历左右子树
    1.如果在左子树中找到了p或q节点，则左子树返回节点，否则返回null,说明p和q节点在右子树
    2.如果在右子树中找到了p或q节点,则右子树返回节点,否则返回null，说明p和q节点在左子树
    3.如果左子树找到，右子树没找到，即左子树!null,右子树返回null,那么说明公共祖先节点就是左子树返回的节点； 
    或者如果左子树没找到，右子树找到，即左子树null,右子树返回!null,那么说明公共祖先节点就是左子树返回的节点； 
    4.如果左右子树都!null,说明p和q位于左右子树，那么根节点就是最近的公共节点
剪枝：如果左子树返回的是公共的最近祖先节点，则不需要递归右子树，但是针对q或p是另一个节点的子节点时，无法剪枝
```
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        return recur(root, p,q);

    }
    public TreeNode recur(TreeNode root, TreeNode p, TreeNode q){
        if(root==null || root==p || root==q){
            //如果root=null,说明已经到了叶子节点都没找到，返回null, 如果找到了p或者q的一个，则返回该节点
            return root;
        }

        //遍历左子树
        TreeNode left=recur(root.left,p,q);
        //遍历右子树
        TreeNode right=recur(root.right,p,q);

        if(left==null){
            //如果左子树没找到，说明一定在右子树
            return right;
        }
 剪枝：如果左子树返回的是公共的最近祖先节点，则不需要递归右子树，但是针对q或p是另一个节点的子节点时，无法剪枝
        if (left != null && left != q && left != p)
            return left;
        if(right==null){
            //如果右子树没找到，说明一定在左子树
            return left;
        }
        //到这里说明左右子树都找到了节点，说明p和q位于左右子树，则最近公共节点就是根节点
        return root;

    }
}
```
