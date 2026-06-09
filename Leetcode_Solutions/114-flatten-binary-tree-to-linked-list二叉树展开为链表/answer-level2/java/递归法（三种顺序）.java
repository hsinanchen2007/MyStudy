这道题解法很多，迭代法其实是最合适的，因为迭代法O(1)的空间复杂度更符合“原地”的概念。但树相关问题大多可用递归解决，故贡献出三种顺序的递归。这道题其实怎样递归，影响都不大，本质还是把左子树插入到根节点和右子树的跟节点之间。
其实递归的思想就是找到相似的子结构。对整棵树而言是根节点的左子树插入到右子树中，对左子树而言是左子树的左子树插入到左子树的右子树中。这就是递归的分解的原因。

1. 先转化左右子树，再拼接
```
class Solution {
    public void flatten(TreeNode root) {
        if (root == null )
            return;
        
        //分别转化左右子树
        flatten(root.left);
        flatten(root.right);
        //左子树插入右子树中，即取代原右子树，原右子树的根节点做好备份
        TreeNode rightNode = root.right;
        root.right = root.left;
        //注意，一定要记得把左指针置空
        root.left = null;
        //沿着原来的左子树到达末尾，拼接上右子树
        TreeNode p = root;
        while (p.right != null)
            p = p.right;
        p.right = rightNode;
    }
}
```

2. 先转化左子树，插入根节点和右子树之间后，再转化右子树
```
public void flatten(TreeNode root) {
        if (root == null )
            return;
            
        flatten(root.left);
        TreeNode rightNode = root.right;
        root.right = root.left;
        root.left = null;
        TreeNode p = root;
        while (p.right != null)
            p = p.right;
        p.right = rightNode;
        
        flatten(rightNode);
    }
```

3. 先将左子树接到根节点的右侧，右子树接到原左子树的最右节点的右侧，再转化原左子树
```
public void flatten(TreeNode root) {
        if (root == null )
            return;
        TreeNode rightNode = root.right;
        root.right = root.left;
        root.left = null;
        TreeNode p = root;
        while (p.right != null) {
            p = p.right;
        }
        p.right = rightNode;
        flatten(root.right);
    }
```

