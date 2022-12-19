给一个目标数和二叉树，寻找一条路径上的节点值之和为sum.这种题避免不了创建List,subList.
肯定又是先左边后右边，在每一次递归函数中最开始都要判断root是不是叶子节点。

if(root.left == null && root.right == null){   //判断是否是叶子节点
    if(sum == 0)           //判断sum 已经是target了。
    List.add(new ArrayList<>(subList));
}
一般情况下可以根据需要引入一个函数helper(root,sum){
}

在一个递归函数的最开始需要进行的操作非常关键，比如边缘条件的考虑（这道题就要考虑root==null）的情况。