map存放key-value，f存放key-times（使用次数）。
之所以使用LinkedHashMap，是为了在使用次数相同时，淘汰掉最久未使用的，即在LinkedHashMap的双向链表里靠前的。
有遍历LinkedHashMap的操作，时间复杂度O(n)，空间复杂度也是O(n)。
使用次数=get+put，没有认真审题提交了n多次。还有就是map满的时候如果put已有的key，是可以直接put，我刚开始还处理特意处理成先remove。

btw，官方的答案为什么总是看起来那么难以理解？
```
class LFUCache {

    private Map<Integer, Integer> map;
    private Map<Integer, Integer> f;
    private int capacity;
    private int size;

    public LFUCache(int capacity) {
        if (capacity <=0) {
            this.capacity = 0;
        } else {
            map = new HashMap<>(capacity);
            f = new LinkedHashMap<>(capacity, .75F, true);
            this.capacity = capacity;
            size = 0;
        }
    }
    
    public int get(int key) {
        if (capacity <= 0) {
            return -1;
        }
        Integer v = map.get(key);
        if (v == null) {
            return -1;
        }
        usePlus(key);
        return v;
    }
    
    public void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        if (map.containsKey(key)) {
            map.put(key, value);
        } else {
            if (capacity == size) {
                size--;
                Integer lfuKey = getLfuKey();
                map.remove(lfuKey);
                f.remove(lfuKey);
            }
            map.put(key, value);
            size++;
        }
        usePlus(key);
    }

    private Integer getLfuKey() {
        Integer k = null;
        int v = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : f.entrySet()) {
            if (entry.getValue() < v) {
                v = entry.getValue();
                k = entry.getKey();
            }
        }
        return k;
    }

    private void usePlus(Integer key) {
        f.put(key, f.get(key)  == null ? 0 : f.get(key) + 1);
    }
}
```
