分为三步：
1. 在每一个结点后面复制一个相同的节点（random指针不复制）
2. 为random指针赋值
3. 链表拆分
```Java
    public Node copyRandomList(Node head) {
        Node p = head, q, newNode;
        // copy
        while (p != null) {
            q = p.next;
            newNode = new Node(p.val);
            newNode.next = q;
            p.next = newNode;
            p = q;
        }
        // random指针赋值
        p = head;
        while (p != null) {
            q = p.next;
            if (p.random != null) q.random = p.random.next;
            p = q.next;
        }
        // 拆分
        p = head;
        Node newHead = (head == null ? null : head.next);
        while (p != null) {
            q = p.next;
            p.next = q.next;
            if (q.next != null) q.next = q.next.next;
            p = p.next;
        }
        return newHead;
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！