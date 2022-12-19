### 实现思路
1. HashMap    保存 key、value
2. LinkedList 保存最新的key

### put方法关键有两点
1. key已经存在：哈希表和链表中都要删除此Key
2. 容量已满：
- 链表中获取最后一个节点并删除
- 哈希表中删除链表中获取的最后一个节点key

``` Java
class LRUCache {
    private int capacity = 0;
    private HashMap<Integer, Integer> hm = null;
    private LinkedList<Integer> linkedList;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        hm = new HashMap<>();
        linkedList = new LinkedList<Integer>();
    }

    public int get(int key) {
        if (!hm.containsKey(key)) {
            return -1;
        }

        linkedList.remove((Integer) key);
        linkedList.addFirst(key);
        return hm.get(key);
    }

    public void put(int key, int value) {
        if (hm.containsKey(key)) {
            hm.remove(key);
            linkedList.remove((Integer) key);
        } else {
            if (linkedList.size() == this.capacity) {
                hm.remove(linkedList.getLast());
                linkedList.removeLast();
            }
        }

        linkedList.addFirst(key);
        hm.put(key, value);
    }
}
```
