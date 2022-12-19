```
class LRUCache {
    LinkedHashMap<Integer,Integer> map;
    public LRUCache(int capacity) {
        map=new LinkedHashMap<Integer,Integer>(16,0.75f,true){
            @Override
            protected boolean removeEldestEntry(Map.Entry eldest) {
                return size()>capacity;
            }
        };
    }
    
    public int get(int key) {
        if(!map.containsKey(key)) return -1;
        return map.get(key);
    }
    
    public void put(int key, int value) {
        map.put(key,value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```
