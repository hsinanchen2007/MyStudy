```
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) return res;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> list = new ArrayList<>(size);//本层结果
//            for (int i = 0; i < size; i++) {
            while (size-- > 0) {
                Node poll = queue.poll();
                list.add(poll.val);
                if (poll.children != null) {
                    for (Node item : poll.children) {
                        queue.add(item);
                    }
                }
            }
            res.add(list);
        }
        return res;
    }
```
