```
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }

        PriorityQueue<Freq> pq = new PriorityQueue<>(new FreqComparator());    // java内部最小堆实现
        for (int key : map.keySet()) {
            if (pq.size() < k) {
                pq.add(new Freq(key, map.get(key)));
            } else if (map.get(key) > pq.peek().freq) {
                pq.remove();
                pq.add(new Freq(key, map.get(key)));
            }
        }

        List<Integer> list = new ArrayList<>();
        while (! pq.isEmpty()) {
            list.add(pq.remove().e);
        }

        return list;
    }

    // 比较器
    private class FreqComparator implements Comparator<Freq> {
        @Override
        public int compare(Freq a, Freq b) {
            return a.freq - b.freq;
        }
    }

    private class Freq {
        int e;       // 元素
        int freq;    // 频次

        public Freq(int e, int freq) {
            this.e = e;
            this.freq = freq;
        }
    }

```
