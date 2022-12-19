### 解题思路
结合注释

### 代码

```java
class LRUCache {
    Map<Integer, Integer> map;
    List<Integer> keys;
    int capacity = 0;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        keys = new ArrayList<>();
        this.capacity = capacity;
    }

    public int get(int key) {
        if (capacity == 0) {
            return -1;
        }
        //不包含key 返回-1；
        if (!map.containsKey(key)) {
            return -1;
        }
        //包含的话，将原来的key删除，再再list尾加上这个key（这样这个key是最新的了）
        remove(key);
        keys.add(key);
        return map.get(key);
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        //如果已经包含这个key，将原来的key删除，再再list尾加上这个key（这样这个key是最新的了）
        if (keys.contains(key)) {
            remove(key);
            keys.add(key);
            //更新值
            map.put(key, value);
            return;
        }
        //如果超过list 存储范围，移除最老的那个
        if (capacity == keys.size()) {
            int remove = keys.get(0);
            keys.remove(0);
            map.remove(remove);
        }
        //加上数据
        keys.add(key);
        map.put(key, value);
    }

    private void remove(int key) {
        for (int i = 0; i < keys.size(); i++) {
            if (keys.get(i) == key) {
                keys.remove(i);
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```