### 解题思路
LinkedList储存key值，实现最近最少使用。
get：
如果存在该key，则先把LinkedList中原来的key值删除，再把key添加到LinkedList末尾，越最近使用的key越靠近LinkedList末尾。
put：
1. 如果存在该key，也要像get一样，先把LinkedList中原来的key值删除，再把key添加到LinkedList末尾，直接调用HashMap的put方法，新的value值就会覆盖旧的value值。
2. 如果put之前元素个数已经达到了容量，则把LinkedList中第一个元素删除，越是最近最少使用的key越靠近LinkedList头部。然后调用HashMap的put方法。
3. 不存在该key，也没有到达容量，直接调用HashMap的put方法。

### 代码

```java
class LRUCache {
    private int capacity;
    private HashMap<Integer,Integer> map;
    private LinkedList<Integer> list;
    public LRUCache(int capacity) {
        this.capacity=capacity;
        map=new HashMap<>();
        list=new LinkedList<>();
    }
    
    public int get(int key) {
        if(map.containsKey(key)){
            list.remove((Integer)key);
            list.addLast(key);
            return map.get(key);
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            list.remove((Integer)key);
            list.addLast(key);
            map.put(key,value);
            return;
        }
        if(list.size()==capacity){
            map.remove(list.removeFirst());
            map.put(key,value);
            list.addLast(key);
        }
        else{
            map.put(key,value);
            list.addLast(key);
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