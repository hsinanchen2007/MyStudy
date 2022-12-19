```
    public int maxDepth(Node root) {
        int res = 0;
        if (root == null) return res;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            res++;
            int size = queue.size();
            while (size-- > 0) {
                Node poll = queue.poll();
                if (poll.children != null) {
                    for (Node item : poll.children) {
                        queue.add(item);
                    }
                }
            }
        }
        return res;
    }
```
