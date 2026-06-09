    public int nthUglyNumber(int n) {
        if (0 == n) {
            return 0;
        }
        List<Long> list = new ArrayList<>();
        list.add(1L);
        PriorityQueue<Long> heap = new PriorityQueue<>();

        for (int i = 0; i < n - 1; i++) {
            long value = list.get(i);
            addIfNotExist(heap, value * 2);
            addIfNotExist(heap, value * 3);
            addIfNotExist(heap, value * 5);
            list.add(heap.poll());
        }
             return Math.toIntExact(list.get(n - 1));
    }

    void addIfNotExist(PriorityQueue<Long> queue, long value) {
        if (queue.contains(value)) {
            return;
        }
        queue.add(value);
    }