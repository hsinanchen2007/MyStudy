 思路：最深叶子节点的公共祖先的左右子树高度相同，也就是最深叶子节点的深度一定相同。
如果左右子树不等高，高度小的那个子树节点的叶子节点的深度肯定不是最深的（因为比高度大的子树深度小）。
所以，最深叶子节点肯定在深度较大的子树当中，采用深度优先搜索，每次只要继续往深度更大的子树进行递归即可。
如果左右子树深度相同，表示获取到了最深叶子节点的最近公共祖先

```
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if (root == null){
            return null;
        }
        int left = depth(root.left);
        int right = depth(root.right);
        if (left == right){
            return root;
        }else if(left > right){
            return lcaDeepestLeaves(root.left);
        }else {
            return lcaDeepestLeaves(root.right);
        }
    }

    private int depth(TreeNode root){
        if (root == null){
            return 0;
        }
        int left = depth(root.left);
        int right = depth(root.right);
        return 1 + Math.max(left,right);
    }
```
