# 思路
  用count表示目前找到了倒数第几位，运用了中序遍历的思想
# 代码
```java
    int count;

    public int kthSmallest(TreeNode root, int k) {
        count = k;
        return helper(root);
    }

    private Integer helper(TreeNode root) {
        if (root.left != null) {
            Integer item = helper(root.left);
            if (item != null) return item;
        }
        if (count == 1) return root.val;
        count--;
        if (root.right != null) return helper(root.right);
        return null;
    }
```