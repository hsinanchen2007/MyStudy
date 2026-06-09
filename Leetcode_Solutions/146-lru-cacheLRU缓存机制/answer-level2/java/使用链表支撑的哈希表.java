### 解题思路
请参考注释，JUC包中有支持LRU的天然内部工具类，使用匿名对象初始化即可完成

### 代码

```java
class LRUCache {

    // JUC中适合作为LRE缓存的就是这个map
    LinkedHashMap<Integer,Integer> map = null;

    // 使用匿名内部类的方式初始化对象
    // 第三个参数一定要设定为true，该参数决定是否启用过时删除对象
    // 并且要覆盖removeEldestEntry方法，如果超过size，则移除最老的对象
    public LRUCache(int capacity) {
        map = new LinkedHashMap<Integer,Integer>(capacity,0.75f,true){
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
        Integer v = map.get(key);
        return v==null?-1:v.intValue();
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