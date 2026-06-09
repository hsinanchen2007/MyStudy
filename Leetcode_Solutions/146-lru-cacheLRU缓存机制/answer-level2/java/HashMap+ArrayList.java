**思路：**
键值对存储：HashMap
记录使用情况：ArrayList
1. get：当keys里已存在该元素，将访问情况数组used中的key移动到used的最后一个（先remove再add）然后返回keys对应的值；
1. put：
    第一种情况：已经包含该元素，需要的操作：更新used集合中key的位置（同get），更新键值对keys；
    第二种情况：不包含且容量未达到上限，需要的操作：添加key到keys和used中，元素数量num加1；
    第三种情况：不包含且容量达到上限，查找used中的第0个元素并将keys中对应的键值对删除，删除used中的第0个元素（此时，得到与第一种情况相同的状态），进行第一种情况的操作。

```
class LRUCache {
    private Map<Integer,Integer> keys = new HashMap<>();    //用于存储键值对
    private List<Integer> used = new ArrayList<>();         //用于记录键值对访问情况，used的第0个元素为最少访问的
    private int cap;                                        //表容量
    private int num = 0;                                    //已有元素数量

    public LRUCache(int capacity) {
        this.cap = capacity;
    }
    
    public int get(int key) {
        if(!keys.containsKey(key)) return -1;
        used.remove((Integer) key);             //以下这两步的操作是更新键值对的使用情况
        used.add(key);
        return keys.get(key);
    }
    
    public void put(int key, int value) {
        if(keys.containsKey(key)){
            used.remove((Integer)key);
        }else if(num < cap){
            num++;
        }else {
            keys.remove(used.get(0));
            used.remove(0);
        }
        keys.put(key,value);
        used.add(key);
    }
}
```
