
首先主要有一下这两个操作：（具体的处理细节，代码有注释！）
- 获取缓存
  - 缓存不存在 返回-1
  - 存在
- 增加缓存存在如下情况：
  - 缓存存在
    - 相同key value相同
    - 相同key value不相同 
  - 缓存不存在
    - 缓存已满
    - 缓存未满

代码采用了哨兵模式简化了代码的判断操作。

代码执行效率如下：
![WechatIMG173.png](https://pic.leetcode-cn.com/0fc05922f7510eaa5226f9484a340f1b5caab94a4bbbdc032418c29d43bd1eeb-WechatIMG173.png)

双向链表只存在两个操作 insetToHead 和 deleteNode，
get操作，如果不存在直接返回，如果存在，需要更新缓存，删除，再插入head即可。
put操作，如果存在 删除，再插入head，如果不存在，判断链缓存是否存满，不满，直接插入head，满了，删除tail，再插入head。

talk is cheap，just show the code
```
import java.util.HashMap;
import java.util.Map;

/**
 * @author: zy
 * @Date: 2020-02-07 09:12
 * @Copyright: 2019 www.lenovo.com Inc. All rights reserved.
 * leetcode LRUCache can use as testcase.
 */
public class LRUCache {
    /**
     * LinkedListHash Map
     */
    private Map<Integer, DoubleLinkedList> cache = new HashMap<>(16);

    /**
     * cache total size
     */
    private int capacity;

    /**
     * cache current size
     */
    private int size;

    /**
     * use solider design to make code sample,less if.
     */
    private DoubleLinkedList head;

    private DoubleLinkedList tail;

    public LRUCache(int capacity) {
        if (capacity == 0) {
            throw new RuntimeException("capacity can not be zero!!!");
        }
        head = new DoubleLinkedList(0, 0);
        tail = new DoubleLinkedList(0, 0);

        head.next = tail;
        tail.pre = head;

        this.capacity = capacity;
    }

    /**
     * Doubly linked list
     */
    static class DoubleLinkedList {

        private int value;

        private int key;

        DoubleLinkedList pre = null;

        DoubleLinkedList next = null;

        DoubleLinkedList(int key, int value) {
            this.value = value;
            this.key = key;
        }
    }
    /**
     * get cache
     * two situations：
     * a:
     * cache exist
     * delete old node.
     * insert node to head.
     * b.cache not exist
     * return -1
     *
     * @param key
     * @return
     */
    public int get(int key) {
        DoubleLinkedList node = cache.get(key);
        if (node == null) {
            return -1;
        }
        deleteNode(node);
        insertToHead(key, node);
        return node.value;
    }

    /**
     * put cache
     * two situations
     * a.cache exist
     * 1.same key has same value.
     * 2.same key has diff value.
     * b.cache not exist
     * 1.cache full
     * 2.cache not full
     *
     * @param key
     * @param value
     */
    public void put(int key, int value) {
        DoubleLinkedList node = cache.get(key);
        DoubleLinkedList newNode = new DoubleLinkedList(key, value);
        if (node == null) {
            insertToHead(key, newNode);
        } else {
            deleteNode(node);
            insertToHead(key, newNode);
        }
        cache.put(key, newNode);
    }

    private void insertToHead(int key, DoubleLinkedList node) {
        if (size >= capacity) {
            cache.remove(tail.pre.key);
            deleteNode(tail.pre);
        }

        node.next = head.next;

        head.next.pre = node;

        head.next = node;

        node.pre = head;

        size++;
    }

    private void deleteNode(DoubleLinkedList node) {

        node.pre.next = node.next;

        node.next.pre = node.pre;

        size--;
    }

}
```
