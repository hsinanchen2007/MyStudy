双hash表解法
```
public class LFUCache {
    private int cap;
    // 存储键值对
    private Map<Integer, Integer> cache = new HashMap<>();
    // 存储每个元素访问频率
    private Map<Integer, HitRate> count = new HashMap<>();

    public LFUCache(int capacity) {
        this.cap = capacity;
    }

    public int get(int key) {
        if (cache.containsKey(key)) {
            //元素访问次数加1
            updateHitCount(key);
            return cache.get(key);
        }
        return -1;
    }

    public void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (cache.containsKey(key)) {
            //元素访问次数加1
            updateHitCount(key);
        } else {
            if (cache.size() == cap) {
                //删除最不频繁使用的元素
                remove();
            }
            //插入新元素
            count.put(key, new HitRate(key, 1, System.nanoTime()));
        }
        cache.put(key, value);
    }

    //移除最不频繁使用的元素
    private void remove() {
        //取最不频繁使用的进行移除
        HitRate hr = Collections.min(count.values());
        cache.remove(hr.key);
        count.remove(hr.key);
    }

    // 更新元素访问评率
    private void updateHitCount(int key) {
        HitRate hr = count.get(key);
        hr.hitCount = hr.hitCount + 1;
        hr.lastTime = System.nanoTime();
    }


    class HitRate implements Comparable<HitRate> {

        private int key;
        private int hitCount;
        private long lastTime;

        private HitRate(int key, int hitCount, long lastTime) {
            this.key = key;
            this.hitCount = hitCount;
            this.lastTime = lastTime;
        }

        @Override
        public int compareTo(HitRate o) {
            // 先比较访问频次
            int compare = Integer.compare(this.hitCount, o.hitCount);
            // 频次相同，再比较最后访问时间
            return compare == 0 ? Long.compare(this.lastTime, o.lastTime) : compare;
        }
    }
}

```
