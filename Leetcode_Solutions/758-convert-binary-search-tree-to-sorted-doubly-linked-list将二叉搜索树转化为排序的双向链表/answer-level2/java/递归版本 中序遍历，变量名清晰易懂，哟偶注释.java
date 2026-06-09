```
// 426. 将二叉搜索树转化为排序的双向链表
    // 构建一个引子节点pre，指向head，遍历完, prev is tail ,然后首尾相连即可
    public TreeNode treeToDoublyList(TreeNode root) {
        if (root == null) return null;
        // pre 上一次迭代的节点，
        TreeNode back = new TreeNode(-1), pre = back;
        Stack<TreeNode> s = new Stack<>();
        TreeNode cur = root;
        while (cur != null || !s.isEmpty()) {
            if (cur != null) {
                s.push(cur);
                cur = cur.left;
            } else {
                cur = s.pop();
                pre.right = cur;
                cur.left = pre;
                pre = cur;
                cur = cur.right;
            }
        }
        TreeNode head =  back.right;
        TreeNode tail =  pre;
        head.left=tail;
        tail.right=head;
        return   head;
    }
```
