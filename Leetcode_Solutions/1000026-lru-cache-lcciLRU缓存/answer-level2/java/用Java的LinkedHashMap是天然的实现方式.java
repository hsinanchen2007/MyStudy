### 解题思路
JDK本身已经提供了这样的类库，只需要一个匿名内部类继承一下就可以了。
即使用JUC（java.util.concurrent）包

但是基本思路还是要说一下：
1. 肯定要使用哈希表，只有这样，搜索的复杂度才能控制到o(1)
2. 为了将元素能够不停的从队列中推出去，所以还必须要构造一个链表，用来不停的将元素推向队列末尾
3. 如果自己实现，必须构造上述两种元素，所以还必须包装一个自定义的Node，该Node包含head和tail指针，实际上LinkedHashMap也是这样实现的

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