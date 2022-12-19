### 思路
1. 受最长连续序列的启发，我们定义递归方程的含义：从当前节点开始，与孩子节点所能构成的连续序列的长度
所以有:
    1. 当前节点与左右子树均能构成递增关系，那么当前节点的连续序列长度为：max(left, right) + 1
    2. 当前节点与左子树构成递增关系，那么当前节点的连续序列长度为：left + 1
    3. 当前节点与右子树构成递增关系，那么当前节点的连续序列长度为：right + 1
    4. 当前节点与左右子树均不能构成递增关系，那么对于当前节点来说，最长的连续序列长度为 1

```
/// 记录最长连续序列的长度
Integer maxValue;

public void setMaxValue(int maxValue) {
    if (this.maxValue == null) {
        this.maxValue = maxValue;
    }
    this.maxValue = Math.max(maxValue, this.maxValue);
}

public int longestConsecutive(TreeNode root) {
    this.setMaxValue(Integer.MIN_VALUE);
    helper(root);
    return maxValue;
}

private int helper(TreeNode root) {
    if (root == null) {
        this.setMaxValue(0);
        return 0;
    }
    if (root.left == null && root.right == null) {
        this.setMaxValue(1);
        return 1;
    }
    /// 以 root 为起点的最长连续序列
    int leftResult = helper(root.left);
    int rightResult = helper(root.right);
    /// 是否与左子树构成递增序列
    boolean isIncreaseLeft = isIncrease(root, root.left);
    /// 是否与右子树构成递增序列
    boolean isIncreaseRight = isIncrease(root, root.right);
    int res;
    if (isIncreaseLeft && isIncreaseRight) {
        /// case 1
        res = Math.max(leftResult + 1, rightResult + 1);
    } else if (isIncreaseLeft) {
        /// case 2
        res = leftResult + 1;
    } else if (isIncreaseRight) {
        /// case 3
        res = rightResult + 1;
    } else {
        /// case 4
        res = 1;
    }
    this.setMaxValue(res);
    return res;
}

private boolean isIncrease(TreeNode root, TreeNode child) {
    if (child == null) {
        return false;
    }
    if (root.val + 1 != child.val) {
        return false;
    }
    return true;
}

```