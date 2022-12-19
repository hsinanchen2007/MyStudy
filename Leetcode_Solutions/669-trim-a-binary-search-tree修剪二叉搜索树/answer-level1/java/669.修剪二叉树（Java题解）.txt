将问题细化为子问题，使用递归求解
判断当前 root.val 的大小在不在 [L, R] 区间内
- 若 root.val < L（即在 [L, R] 区间左侧），需要抛弃根节点，从右子树中修剪 [L, R] 内的值
- 若 root.val > R（即在 [L, R] 区间右侧），需要抛弃根节点，从左子树中修剪 [L, R] 内的值
- 若 L <= root.val <= R（即在 [L, R] 区间中），保留根节点，从右子树中修剪 [L, root.val - 1] 内的值，从左子树中修剪 [root.val + 1, R] 内的值

```java
class Solution {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (root == null || L > R) return null;
        if (L > root.val) return trimBST(root.right, L, R);
        if (R < root.val) return trimBST(root.left, L, R);
        root.left = trimBST(root.left, L, root.val - 1);
        root.right = trimBST(root.right, root.val + 1, R);
        return root;
    }
}
```
![QQ截图20191111151526.jpg](https://pic.leetcode-cn.com/9580337d3c26a71702f6579c977ae62eeec2c3e3fa2f06d0a61afae7242f1228-QQ%E6%88%AA%E5%9B%BE20191111151526.jpg)
