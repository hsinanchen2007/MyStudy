![image.png](https://pic.leetcode-cn.com/524b803365e608b0678110d5b524b218d3b763832ced44e9a45b62f8114ec576-image.png)

```java
public int sumOfLeftLeaves(TreeNode root) {
    if (root == null) return 0;
    if (root.left == null) return  sumOfLeftLeaves(root.right); //如果左子树为空，那么只需返回右子树的左叶子和
    if (root.left.left == null && root.left.right == null) // 如果左子树为叶子节点，那么需返回右子树的左叶子和 + 左孩子的值
        return sumOfLeftLeaves(root.right) + root.left.val;
    return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right); // 其他情况需返回左右子树的左叶子和之和
}
```

