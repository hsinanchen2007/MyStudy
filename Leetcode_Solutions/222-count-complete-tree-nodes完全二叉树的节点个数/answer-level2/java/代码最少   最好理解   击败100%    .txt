# 思路
  首先通过不断探索右子节点计算深度**depth**，然后将节点分成两部分：
    1. 由**depth**深度组成的完整金字塔（root到倒数第二层一定填满）
    2. 最后一层的节点
  使用helper()函数计算最后一层节点的数量，传入的**depth**是下面最多还有的深度，所以**depth == 0**也就是深度遍历终止的地方，此处有节点返回1，无节点返回0。
  **关键的剪枝操作**：当左子树的最后一层的节点没有充满时，直接返回左子树中的最后一层的节点数（右子树最后一层一定没有节点）。
# 代码
```java
    public int countNodes(TreeNode root) {
        int depth = 0;
        TreeNode temp = root;
        while (temp != null){
            depth++;
            temp = temp.right;
        }
        int bottom = helper(root, depth);
        return (1 << depth) - 1 + bottom;
    }

    private int helper(TreeNode root, int depth) {
        if (depth == 0) {
            if (root != null) return 1;
            return 0;
        }
        int left = helper(root.left, depth - 1);
        if (left != 1 << depth - 1) return left;
        return left + helper(root.right, depth - 1);
    }
```