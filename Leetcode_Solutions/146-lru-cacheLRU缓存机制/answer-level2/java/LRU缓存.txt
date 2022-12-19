### 解题思路
1. 首先有一个工具包LinkedHashMap，具有LRU的特点。其中的removeEldestEntry方法需要重写如下，才能满足条件。
2. 第二种方法使用了hashmap和队列来解决，貌似不是O（1）。。。不过也不是O（n），跟用户操作相关。。

### 代码

```java
class LRUCache {
    private int capacity;
    private Map map;
    public LRUCache(int capacity) {
        map = new LinkedHashMap(capacity, 0.75F, true){
            protected boolean removeEldestEntry(Map.Entry eldest){
                return size() > capacity;
            }
        };
    }

    public int get(int key) {
        return (int)map.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        map.put(key, value);
    }
}
class LRUCache {
    int maxLen = 0;
    Map<Integer, Pair<Integer, Integer>> map = new HashMap<>();
    Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
    public LRUCache(int capacity) {
        maxLen = capacity;
    }
    
    public int get(int key) {
        if(!map.containsKey(key)) return -1;
        int value = map.get(key).getKey();
        int count = map.get(key).getValue();
        map.put(key, new Pair(value, count+1));
        queue.add(new Pair(key, count+1));
        return value;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            int count = map.get(key).getValue();
            map.put(key, new Pair(value, count+1));
            queue.add(new Pair(key, count+1));
        }
        else{
            if(map.size() >= maxLen){
                Pair<Integer, Integer> pair = queue.poll();
                while(pair.getValue() != map.get(pair.getKey()).getValue()) pair = queue.poll();
                map.remove(pair.getKey());
            }
            map.put(key, new Pair(value, 0));
            queue.add(new Pair(key, 0));
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