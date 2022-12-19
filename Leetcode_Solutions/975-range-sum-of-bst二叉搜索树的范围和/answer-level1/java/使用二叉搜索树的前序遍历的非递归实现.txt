>思路：使用栈的后进先出(LIFO)特性
1. 现将二叉搜索树的根节点压入栈中
2. 出栈栈顶元素，在依次将右子树、左子树压入栈中

```
public static int rangeSumBST(TreeNode root, int L, int R) {
        int sum = 0;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode cur = stack.pop();
            if (cur.val >= L && cur.val <= R) {
                sum += cur.val;
            }
            if (cur.right != null) stack.push(cur.right);
            if (cur.left != null) stack.push(cur.left);
        }
        return sum;
    }
```