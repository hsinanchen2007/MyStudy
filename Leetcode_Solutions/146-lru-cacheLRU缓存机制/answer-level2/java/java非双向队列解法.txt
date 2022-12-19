### 解题思路
最开始使用currentTimeMillis发现解答一直错误，之后仔细想了下，发现是因为计算机执行的太快，currentTimeMillis很多时候都是一样的值，当时觉得以时间计数不可行，看了题解准备用双向队列实现，实现之后突然想到，如果把currentTimeMillis换成更小的单位，说不定就能成功了，因此换成了nanoTime。
剩下的思路非常简单，就是用java自带的PriorityQueue维护一个以时间为索引的小顶堆，为了更快找到，用HashMap维护一个key和队列中的对象的对应关系。
最后执行用时确实是不如双向队列的，因为题解里都是双向队列的解法，在这里提供一个另一种思路。

### 代码

```java

class LRUCache {
    private int capacity;
    private PriorityQueue<CacheInfo> queue;
    private Map<Integer, CacheInfo> record = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        queue = new PriorityQueue<>((o1, o2) -> {
            // 以时间为索引的小顶堆
            long temp = o1.latestTime - o2.latestTime;
            if (temp > 0) {
                return 1;
            } else if (temp < 0) {
                return -1;
            } else {
                return 0;
            }
        });
    }

    public int get(int key) {
        CacheInfo cache = record.get(key);
        if (cache == null) {
            return -1;
        }
        refresh(cache, cache.value);
        return cache.value;
    }

    private void refresh(CacheInfo cache, int val) {
        queue.remove(cache);
        cache.value = val;
        cache.latestTime = System.nanoTime();
        queue.add(cache);
    }

    public void put(int key, int value) {
        CacheInfo cache = record.get(key);
        if (cache != null) {
            refresh(cache, value);
            return;
        }
        cache = new CacheInfo(key, value);
        if (queue.size() >= capacity) {
            // 此时需要清除最久未操作的数据
            CacheInfo temp = queue.poll();
            record.remove(temp.key);
        }
        queue.add(cache);
        record.put(key, cache);
    }

    static class CacheInfo {
        // 小顶堆
        long latestTime;
        int key;
        int value;

        CacheInfo(int key, int value) {
            this.latestTime = System.nanoTime();
            this.key = key;
            this.value = value;
        }
    }
}
```