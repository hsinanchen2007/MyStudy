***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode/blob/master/java/tree/%24617_MergeTwoBinaryTrees.java)，持续更新。***

递归终止条件：如果两方有一个为null，直接返回另一个。

如果两个节点都不为null，则根据两个节点和创建节点，再递归构建左右节点即可。

```
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
    //如果两方有一个为null，直接返回另一个
    if(t1 == null) return t2;
    if(t2 == null) return t1;
    //两个节点都不为null
    TreeNode root = new TreeNode(t1.val+t2.val);
    root.left = mergeTrees(t1.left,t2.left);
    root.right = mergeTrees(t1.right,t2.right);
    return root;
}
```

