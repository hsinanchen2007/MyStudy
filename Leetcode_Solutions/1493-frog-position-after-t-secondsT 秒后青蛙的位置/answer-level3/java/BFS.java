    public double frogPosition(int n, int[][] edges, int t, int target) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] edge : edges) {
            int a = Math.min(edge[0], edge[1]);
            int b = Math.max(edge[0], edge[1]);
            map.putIfAbsent(a, new ArrayList<>());
            map.get(a).add(b);
        }
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(1, 1d));
        int steps = 0;
        while (true) {
            int size = queue.size();
            while (size-- > 0) {
                Node node = queue.poll();
                List<Integer> list = map.get(node.val);
                if (node.val == target) return (steps == t || list == null) ? node.prob : 0;
                if (list == null) continue;
                double p = node.prob / list.size();
                for (int v : list) queue.offer(new Node(v, p));
            }
            if (steps++ == t) return 0;
        }
    }

    class Node {
        int val;
        double prob;
        Node(int val, double prob) {
            this.val = val;
            this.prob = prob;
        }
    }