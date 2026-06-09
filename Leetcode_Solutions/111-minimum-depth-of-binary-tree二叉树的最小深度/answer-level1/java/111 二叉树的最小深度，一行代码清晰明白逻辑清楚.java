```java
    /**
     * 执行用时 :0 ms, 100.00%
     * 内存消耗 :38 MB, 49.42%
     *
     * 思路:
     * 1 若根为null, 则最小深度为0
     * 2 若左子树为null, 则返回右子树最小深度加1
     * 3 若右子树为null, 则返回左子树最小深度加1
     * 4 若左、右子树都不为null, 则返回左、右子树最小深度的较小值加1
     */
    public int minDepth(TreeNode root) {
        return root == null ? 0 :
                root.left == null ? minDepth(root.right) + 1 :
                        root.right == null ? minDepth(root.left) + 1 :
                                Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
```
