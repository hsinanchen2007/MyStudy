![image.png](https://pic.leetcode-cn.com/90c5d48950cb77889b54899e1ade1ff43d4f7ea7e845b2d3968b7475d16febe6-image.png)

直接上代码：
首先，注意二叉搜索树的特性，左子树均小于根节点，右子树均大于根节点
```
public TreeNode trimBST(TreeNode root, int L, int R) {
    if (root == null) return null;
    root.left = trimBST(root.left,L,R);
    root.right = trimBST(root.right,L,R);
    if (root.val < L){  //如果根节点小于最小值L，那么左孩子必然也小于L，所以只需返回修剪后的右子树
        return root.right;
    }else if (root.val > R){    //此处也同理，根节点和右孩子均大于R，那么返回修剪后的左子树即可
        return root.left;
    }else { //此处说明根节点在[L,R]范围内，返回根节点即可（其左右子树在前面已经修剪过了）
        return  root;
    }
}
```

