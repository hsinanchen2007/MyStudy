```
public Node connect(Node root) {
        if (root == null) return null;
        Deque<Node> deque = new LinkedList();
        deque.addFirst(root);
        while (!deque.isEmpty()) {
            Node tmp = deque.pollLast();
            int size = deque.size();
            if (tmp.left != null) deque.addFirst(tmp.left);
            if (tmp.right != null) deque.addFirst(tmp.right);
            for (int i=0;i<size;i++) {
                Node node = deque.pollLast();
                tmp.next = node;
                tmp = tmp.next;
                if (node.left != null) deque.addFirst(node.left);
                if (node.right != null) deque.addFirst(node.right);
            }
        }
        return root;
    }
```
