这里要注意题目：一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。说的是可能穿过根节点，不是一定穿过。我在解题的时候误认为最大值就是根节点左子树深度+根节点右子树最大深度，却忽略了不会穿过根节点的情况，如下图：根节点的最大值是6，但是左孩子-5这个结点的最大值是7且没有经过根节点。
![树.PNG](https://pic.leetcode-cn.com/9a526a2f654702d258c61c95fdc1711e9e41821feefaa0273034958eb6674f31-%E6%A0%91.PNG)
所以在函数外面定义一个max保存当前的最大值，让根节点和的左右孩子和和当前的最大值进行比较，入过大于前面的最大值就要跟新max值。
```
public int max = 0;
public int diameterOfBinaryTree(TreeNode root) {
   helper(root);
   return max;
}


private int helper(TreeNode root) {
 if(root == null) return 0;
    int l = helper(root.left);
    int r = helper(root.right);
    max = Math.max(max, r+l);
    return Math.max(r,l)+ 1;
}


```