LinkedHashMap实现

class LRUCache {
    
    LinkedHashMap<Integer, Integer> map;
    int maxCapacity;
    public LRUCache(int capacity) {
        map = new LinkedHashMap<>(capacity);
        this.maxCapacity = capacity;
    }
    
    public int get(int key) {
        int result;
        if(map.containsKey(key)) {
            result = map.get(key);
            map.remove(key);
            map.put(key, result);
        } else {
            result = -1;
        }
        
        return result;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)) {
            map.remove(key);
            map.put(key, value);
            return;
        }
        
        if(map.size() == maxCapacity) {
            int first = map.keySet().iterator().next();
            map.remove(first);
        }
        map.put(key, value);
    }
}