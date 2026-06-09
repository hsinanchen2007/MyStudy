### 解题思路
利用两个HashMap，一个记录(Key,Value)。另一个用LinkedHasMap记录(Key,Frequency)，实现LRU（最近最少使用）解决平局问题(即两个或更多个键具有相同使用频率)。
1.get操作：如果Map中含有该元素，则返回value值，并需要更新LinkedHasMap，来保证LRU顺序。否则返回-1.
2.put操作：如果Map中含有该元素，则更新两个Map(注意LinkedHasMap，保证LRU顺序)。否则先判断Map是否已满，若已满则遍历LinkedHashMap寻找最小frequency的key将其删除(LinkdedHashMap维护LRU顺序，解决了平局问题)，将新值加入Map中。
### 代码

```java
class LFUCache {
    private static int capacity;
    Map<Integer,Integer> lfu1;//记录Key Value
    Map<Integer,Integer> lfu2;//记录Key Frequency
    public LFUCache(int capacity) {
        this.capacity = capacity;
        lfu1 = new HashMap<Integer,Integer>();
        //用LinkedHasMap实现LRU（最近最少使用），当存在平局（即两个或更多个键具有相同使用频率）
        lfu2 = new LinkedHashMap<Integer,Integer>();
    }
    
    public int get(int key) {
        if(lfu1.containsKey(key)){
            //更新lfu2，保证LRU顺序
            int freq = lfu2.remove(key);
            lfu2.put(key,freq+1);

            return lfu1.get(key);
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(lfu1.containsKey(key)){
            //更新lfu2，保证LRU顺序
            int freq = lfu2.remove(key);
            lfu2.put(key,freq+1);

            lfu1.put(key,value);
        }else{
            if(lfu1.size() >= capacity){//遍历lfu2, 找到最小的frequency，从lfu1，lfu2中删除
                int min = Integer.MAX_VALUE;//记录最小的frequency
                int key3 = key;//记录最小frequency的key值
                for(int key2 : lfu2.keySet()){
                    if(min > lfu2.get(key2)){
                        min = lfu2.get(key2);
                        key3 = key2;
                    }
                }
                lfu1.remove(key3);
                lfu2.remove(key3);
            }
            lfu1.put(key,value);
            lfu2.put(key,1);
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```