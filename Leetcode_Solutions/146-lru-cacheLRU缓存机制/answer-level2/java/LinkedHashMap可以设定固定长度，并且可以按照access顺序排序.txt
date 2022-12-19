### 解题思路
`        super(capacity, 0.75F, true);` 这个一定要有第三个参数，这个是AccessOrder，访问顺序排序链表
```java
    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        if(size() > capacity) return true;
        else return false;
    }```
这个方法就是确定，hash链表的长度的，当长度大于一定值得时，就删除最老的。
### 代码

```java
class LRUCache extends LinkedHashMap<Integer, Integer> {

    LinkedHashMap<Integer, Integer> lmap = new LinkedHashMap<Integer, Integer>();
    private int capacity;
    public LRUCache(int capacity) {
        // 第三个参数是accessOrder，默认是false。
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }
    
    public int get(int key) {
        return super.getOrDefault(key, -1);
    }
    
    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        if(size() > capacity) return true;
        else return false;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```