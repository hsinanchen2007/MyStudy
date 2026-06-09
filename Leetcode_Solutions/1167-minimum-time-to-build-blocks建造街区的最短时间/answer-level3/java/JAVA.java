    public int minBuildTime(int[] blocks, int split) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int b : blocks) {
            pq.add(b);
        }
        while (pq.size() > 1) {
            pq.poll();
            int b = pq.poll();
            pq.add(split + b);
        }
        return pq.peek();
    }