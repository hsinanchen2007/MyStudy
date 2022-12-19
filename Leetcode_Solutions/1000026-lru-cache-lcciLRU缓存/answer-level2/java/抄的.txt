### 解题思路
抄别人的
### 代码

```java
class LRUCache {

 Map<Integer,Integer> cache = null;

    // 这个是匿名内部类
    // LinkedHashMap的三个构造函数分别是初始容量，扩容因子和是否移除旧的元素
    public LRUCache(int capacity) {
        cache = new LinkedHashMap<>(capacity,0.75f,true){
            // 必须覆盖该方法来保证移除旧的元素
            // 返回false，不删除
            @Override
            protected boolean removeEldestEntry(Map.Entry eldest) {
                if(this.size() > capacity){
                    return true;
                }
                return false;
            }
        };
    }

    public int get(int key) {
        Integer v = this.cache.get(key);
        return v==null?-1:v.intValue();
    }

    public void put(int key, int value) {
        this.cache.put(key,value);
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```