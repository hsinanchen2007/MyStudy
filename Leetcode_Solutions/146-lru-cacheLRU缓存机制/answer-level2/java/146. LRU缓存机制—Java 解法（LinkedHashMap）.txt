## 解题思路

LRU 即 Least Recently Used ，具有淘汰最近最少使用数据的功能。
LRU 需要实现两个功能：
* 缓存功能
* 淘汰机制

## 解题方式
在 Java 中通过 ***Key-Value*** 的形式存储查询数据，第一个想到的就是 ***HashMap***。

那么淘汰机制呢？涉及到两点：
* 怎么对数据进行使用顺序的排列
* 怎么删除淘汰数据

而其中的 ***LinkedHashMap*** 通过设置 ***accessOrder*** 决定按照**插入顺序**还是**访问顺序**记录数据。
* accessOrder 默认为 false，按插入顺序排序
* accessOrder 按访问顺序记录

再重写 ***removeEldestEntry*** 方法，***LinkedHashMap*** 会在插入时帮忙删除数据。

```
public class LRUCache {
    LinkedHashMap<Integer, Integer> hashMap;

    public LRUCache(int capacity) {


        hashMap = new LinkedHashMap<Integer, Integer>(capacity, 0.75f, true) {
            @Override
            protected boolean removeEldestEntry(Map.Entry eldest) {

                return size() > capacity;
            }
        };
    }

    public int get(int key) {
        return hashMap.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        hashMap.put(key, value);
    }

}
```

也可以仿照 ***LinkedHashMap*** ，通过 HashMap + 双链表 自己实现 LRU。