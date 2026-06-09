注意本题是返回一个循环链表

```Java
    Node pre = null;
    public Node treeToDoublyList(Node root) {
        if (root == null) return null;
        this.pre = null;
        convertHelper(root);
        // 找到头和尾结点，连成循环链表
        Node p = root, q = root;
        while(p.left != null) p = p.left;
        while(q.right != null) q = q.right;
        p.left = q;
        q.right = p;
        return p;
    }
    // 中序遍历 记录前一个访问的节点
    // 使用全局变量保存pre，在convertHelper中传pre的值不行
    private void convertHelper(Node cur) {
        if (cur == null) return;
        convertHelper(cur.left);

        cur.left = this.pre;
        if (pre != null) this.pre.right = cur;
        this.pre = cur;

        convertHelper(cur.right);
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！