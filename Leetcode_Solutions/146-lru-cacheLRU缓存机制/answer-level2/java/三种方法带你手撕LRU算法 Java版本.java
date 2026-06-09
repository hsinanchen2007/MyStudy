# 手撕LRU缓存淘汰算法

## LRU介绍

LRU是Least Recently Used的缩写，即最近最少使用，是一种常用的页面置换算法，选择最近最久未使用的页面予以淘汰。 

面试中常考的题目，运用你所掌握的数据结构，自己设计手写LRU算法。

相关题目可参考LeetCode146题

## 一. 使用LinkedHashMap实现

在Java中，其实LinkedHashMap已经实现了LRU缓存淘汰算法，需要在构造函数第三个参数传入true，表示按照时间顺序访问。可以直接继承LinkedHashMap来实现。

但是LinkedHashMap会自动扩容，如果想实现限制容量删除队列顶端元素，需要重写removeEldestEntry()方法，当map里面的元素个数大于了缓存最大容量，删除链表的顶端元素。

```java
public class LRULinkedHashMap<K, V> extends LinkedHashMap<K, V> {

    private int capacity;

    LRULinkedHashMap(int capacity) {
        // 初始大小，0.75是装载因子，true是表示按照访问时间排序
        super(capacity, 0.75f, true);
        //传入指定的缓存最大容量
        this.capacity = capacity;
    }

    /**
     * 实现LRU的关键方法，如果map里面的元素个数大于了缓存最大容量，则删除链表的顶端元素
     */
    @Override
    protected boolean removeEldestEntry(Map.Entry<K, V> eldest) {
        return size() > capacity;
    }
}
```



## 二. 使用LinkedList+HashMap实现

也可以使用LinkedList和HashMap实现，但时间复杂度较高。使用HashMap可以通过O(1)时间拿到元素，但是无法在O(1)时间定位它在链表中的位置，在LinkedList里访问元素仍然是顺序遍历，所以删除元素的时间复杂度仍然是O(n)。并不是高效的Lru算法。

因为从HashMap中删除元素需要Key，所以这里在链表中存放Key而不是Value。

```java
public class LRUCacheBeta<K, V> {
    int capacity;
    Map<K, V> map;
    LinkedList<K> list;

    public LRUCacheBeta(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.list = new LinkedList<>();
    }

    /**
     * 添加元素
     * 1.元素存在，放到队尾
     * 2.不存在，判断链表是否满。
     * 如果满，则删除队首元素，放入队尾元素，删除更新哈希表
     * 如果不满，放入队尾元素，更新哈希表
     */
    public void put(K key, V value) {
        V v = map.get(key);
        if (v != null) {
            list.remove(key);
            list.addLast(key);
            map.put(key, value);
            return;
        }

        //队列未满，添加到尾部
        if (list.size() < capacity) {
            list.addLast(key);
            map.put(key, value);
        } else {
            //队列已满，移除队首
            K firstKey = list.removeFirst();
            map.remove(firstKey);
            list.addLast(key);
            map.put(key, value);
        }
    }

    /**
     * 访问元素
     * 元素存在，放到队尾
     */
    public V get(K key) {
        V v = map.get(key);
        if (v != null) {
            list.remove(key);
            list.addLast(key);
            return v;
        }
        return null;
    }
}
```



## 三. 使用双向链表结构+HashMap实现

在方法二中，删除操作的时间复杂度仍是O(n)，那么如何使其复杂度降为O(1)？我们可以自定义双向链表的结构，这里定义了内部类Node，存放KV以及前后指针。这样我们通过hashmap找到对应Node，然后根据其前驱节点进行指针的操作，就可以实现复杂度O(1)的删除操作。

同样因为访问HashMap需要key，所以定义Node节点存放了K和V，而不是只存放V。保存队列的头节点和尾节点。

在代码中，我们通过调整指针，定义了三个方法，分别是添加元素到队尾，将队列中元素移动到队尾，删除队列头节点并返回，因为是双向链表，特别注意指针变换的顺序以及不要遗漏前驱和后继指针。

```java
public class LRUCache<K, V> {
    private int size;
    private HashMap<K, Node> map;
    private Node head;
    private Node tail;

    LRUCache(int size) {
        this.size = size;
        map = new HashMap<>();
    }

    /**
     * 添加元素
     * 1.元素存在，将元素移动到队尾
     * 2.不存在，判断链表是否满。
     * 如果满，则删除队首元素，放入队尾元素，删除更新哈希表
     * 如果不满，放入队尾元素，更新哈希表
     */
    public void put(K key, V value) {
        Node node = map.get(key);
        if (node != null) {
            //更新值
            node.v = value;
            moveNodeToTail(node);
        } else {
            Node newNode = new Node(key, value);
            //链表满，需要删除首节点
            if (map.size() == size) {
                Node delHead = removeHead();
                map.remove(delHead.k);
            }
            addLast(newNode);
            map.put(key, newNode);
        }
    }

    public V get(K key) {
        Node node = map.get(key);
        if (node != null) {
            moveNodeToTail(node);
            return node.v;
        }
        return null;
    }

    public void addLast(Node newNode) {
        if (newNode == null) {
            return;
        }
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            //连接新节点
            tail.next = newNode;
            newNode.pre = tail;
            //更新尾节点指针为新节点
            tail = newNode;
        }
    }

    public void moveNodeToTail(Node node) {
        if (tail == node) {
            return;
        }
        if (head == node) {
            head = node.next;
            head.pre = null;
        } else {
            //调整双向链表指针
            node.pre.next = node.next;
            node.next.pre = node.pre;
        }
        node.pre = tail;
        node.next = null;
        tail.next = node;
        tail = node;
    }

    public Node removeHead() {
        if (head == null) {
            return null;
        }
        Node res = head;
        if (head == tail) {
            head = null;
            tail = null;
        } else {
            head = res.next;
            head.pre = null;
            res.next = null;
        }
        return res;
    }

    class Node {
        K k;
        V v;
        Node pre;
        Node next;

        Node(K k, V v) {
            this.k = k;
            this.v = v;
        }
    }
}
```

[github代码地址](https://github.com/icecrea/leetcode/tree/master/src/main/java/com/example/summary/lru)



公众号：《编程呓语》欢迎关注
![](https://pic.leetcode-cn.com/c890548cf9be97b923cbc5d9069856d5c2d7fff804635a2b6da5f9a4a69e6306.jpg)

