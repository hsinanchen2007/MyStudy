题目要求原地展开为链表。原地的意思，一个是展开的结果，反应在传入参数，另一个是不能使用容器。所以前序遍历标准套路，使用栈、队列存储节点的方案，就不符合题目要求了。

题目的关键，每遍历一个节点，就让链表的last节点指向它，就可以了。但是通过递归的入参、出参传递这个信息，需要在增加大量的判断逻辑。可以考虑用全局变量存储传递这个信息。是否豁然开朗？

如此，就可以用标准的前序遍历了。

```
    // 增加全局last节点
    TreeNode last = null;
    private void recursion(TreeNode root) {
        if (root == null) return;
        // 前序：注意更新last节点，包括更新左右子树
        if (last != null) {
            last.left = null;
            last.right = root;
        }
        last = root;
        // 前序：注意备份右子节点，规避下一节点篡改
        TreeNode copyRight = root.right;
        recursion(root.left);
        recursion(copyRight);
    }
```