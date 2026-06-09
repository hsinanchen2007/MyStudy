
```java
    Map<Integer, Integer> map;
    Map<Integer, Integer> count;
    Queue<Integer> queue;
    int capacity;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        count = new HashMap<>();
        queue = new LinkedList<>();
        this.capacity = capacity;
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            count.put(key, count.get(key) + 1);
            queue.offer(key);
            return map.get(key);
        }else return -1;
    }

    public void put(int key, int value) {
        if (map.size() >= capacity && !map.containsKey(key) && !queue.isEmpty()) {
            int k = queue.poll();
            while (count.get(k) > 1) {
                count.put(k, count.get(k) - 1);
                if (queue.isEmpty()) break;
                k = queue.poll();
            }
            count.put(k, count.get(k) - 1);
            map.remove(k);
        }
        map.put(key, value);
        count.put(key, count.getOrDefault(key, 0) + 1);
        queue.offer(key);
    }
```