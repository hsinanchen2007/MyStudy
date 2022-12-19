
参考下面链接里的写的, 文章里面写得很清楚, 没有花太多时间

https://medium.com/algorithm-and-datastructure/lfu-cache-in-o-1-in-java-4bac0892bdb3

```
class LFUCache {

    private int cap; //Cache 容量
    private Map<Integer, Integer> vals; //存val的Map
    private Map<Integer, Integer> counter; // 存访问次数
    private Map<Integer, LinkedHashSet<Integer>> freqList; //同一个访问次数，有多少个Key(插入顺序)
    private int leastFreq = -1;

    public LFUCache(int capacity) {
       cap = capacity;
       vals = new HashMap<>();
       counter = new HashMap<>();
       freqList = new HashMap<>();
       freqList.put(1, new LinkedHashSet<>());
    }
    
    public int get(int key) {
        if(!vals.containsKey(key)){
            return -1;
        }
        int value = vals.get(key);
        //freq + 1, 并且将在原来count的列表下删掉加入count + 1的列表
        int count = counter.get(key);
        counter.put(key, count + 1);
        freqList.get(count).remove(key);
        if(!freqList.containsKey(count + 1)){
            freqList.put(count + 1, new LinkedHashSet<>());
        }
        freqList.get(count + 1).add(key);
        //如果当前被访问的key是唯一一个频率最低的key, 那么当前这个key的访问频率仍为最低 == leastFreq + 1;
        if(count == leastFreq && freqList.get(count).size() == 0){
            leastFreq++;
        }
        return value;
    }
    
    public void put(int key, int value) {
        if(cap <= 0) return;
        if(vals.containsKey(key)){
            vals.put(key, value);
            //如果key已经存在，那么不仅要更改它的值,也需要通过get来调整它的访问频率
            get(key);
        }else{
            if(vals.size() >= cap){
               // 如果超过容量, 就淘汰最低频率列表中的第一个, 插入顺序也就是least recently used.
               int evit = freqList.get(leastFreq).iterator().next();
               vals.remove(evit);
               counter.remove(evit);
               freqList.get(leastFreq).remove(evit);
            }
            //新key, 频率是1.
            leastFreq = 1;
            vals.put(key, value);
            counter.put(key, 1);
            freqList.get(1).add(key);
        }
    }
}
```


