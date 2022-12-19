使用leetcode 112题目的案例进行分析，给定如下二叉树，以及目标和 sum = 22

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
我们不难得出规律：任意一条路径权值的总和=当前节点的权值+其**路径上**所有子节点的权值。
例如路径8->4->1，8节点的权值总和为13，4节点的权值总和为5，1节点（叶子节点）的权值总和为其
自身。**当前节点权值总和减去当前节点的权值即为子路径的权值总和。**
因此我们可以递归不断求该路径上子节点的权值，当当前节点为叶子节点而且其权值等于当前节点开始的
所有子节点的权值总和时，我们就找到了符合的节点。
```
public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null) {
        return false;
    }
    // 同时要求为叶子节点，层层递减下来的
    if (root.val == sum && root.left == null && root.right == null) {
        return true;
    }

    return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
}代码块
```

