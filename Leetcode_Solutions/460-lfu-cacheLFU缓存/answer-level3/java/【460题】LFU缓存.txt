### 解题思路
此处撰写解题思路

### 代码

```java
class LFUCache {

    // 存储缓存的内容。
    Map<Integer, Node> cache;
    // firstLinkedList.post 是频次最大的双向链表。
    DoublyLinkedList firstLinkedList;
    // lastLinkedList.pre 是频次最小的双向链表。
    DoublyLinkedList lastLinkedList;
    int size;
    int capacity;

    public LFUCache(int capacity) {
        cache = new HashMap<> (capacity);
        firstLinkedList = new DoublyLinkedList();
        lastLinkedList = new DoublyLinkedList();
        firstLinkedList.post = lastLinkedList;
        lastLinkedList.pre = firstLinkedList;
        this.capacity = capacity;
    }

    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        // 更新访问频次。
        freqInc(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node node = cache.get(key);
        // 若key存在，则更新value，更新访问频次。
        if (node != null) {
            node.value = value;
            freqInc(node);
        } else {
            // 若key不存在，则创建新节点插入。
            if (size == capacity) {
                // 删除最小频次的链表中的最后一个节点，如果该链表中的空了，则删掉该链表。
                cache.remove(lastLinkedList.pre.tail.pre.key);
                lastLinkedList.removeNode(lastLinkedList.pre.tail.pre);
                size--;
                if (lastLinkedList.pre.head.post == lastLinkedList.pre.tail) {
                    removeDoublyLinkedList(lastLinkedList.pre);
                } 
            }
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            if (lastLinkedList.pre.freq != 1) {
                DoublyLinkedList newDoublyLinedList = new DoublyLinkedList(1);
                addDoublyLinkedList(newDoublyLinedList, lastLinkedList.pre);
                newDoublyLinedList.addNode(newNode);
            } else {
                lastLinkedList.pre.addNode(newNode);
            }
            size++;
        }
    }

    void freqInc(Node node) {
        // 将node从原freq对应的双向链表里移除, 如果链表空了则删除链表。
        DoublyLinkedList linkedList = node.doublyLinkedList;
        DoublyLinkedList preLinkedList = linkedList.pre;
        linkedList.removeNode(node);
        if (linkedList.head.post == linkedList.tail) {
            removeDoublyLinkedList(linkedList);
        }
        // 将node加入新freq对应的双向链表，若该链表不存在，则先创建该链表。
        node.freq++;
        if (preLinkedList.freq != node.freq) {
            DoublyLinkedList newDoublyLinedList = new DoublyLinkedList(node.freq);
            addDoublyLinkedList(newDoublyLinedList, preLinkedList);
            newDoublyLinedList.addNode(node);
        } else {
            preLinkedList.addNode(node);
        }
    }

    void addDoublyLinkedList(DoublyLinkedList newDoublyLinedList, DoublyLinkedList preLinkedList) {
        // 创建代表对应访问频次的双向链表。
        newDoublyLinedList.post = preLinkedList.post;
        newDoublyLinedList.post.pre = newDoublyLinedList;
        newDoublyLinedList.pre = preLinkedList;
        preLinkedList.post = newDoublyLinedList;
    }

    void removeDoublyLinkedList(DoublyLinkedList doublyLinkedList) {
        // 删除对应访问频次的双向链表。
        doublyLinkedList.pre.post = doublyLinkedList.post;
        doublyLinkedList.post.pre = doublyLinkedList.pre;
    }
}

class Node {
    int key;
    int value;
    int freq = 1;
    // Node所在频次的双向链表的前继Node 。
    Node pre;
    // Node所在频次的双向链表的后继Node 。
    Node post;
    // Node所在频次的双向链表。
    DoublyLinkedList doublyLinkedList;

    public Node() {}
    
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

class DoublyLinkedList {
    // 该双向链表存储的访问频次。
    int freq;
    // 该双向链表的前继链表（pre.freq < this.freq）。
    DoublyLinkedList pre;
    // 该双向链表的后继链表 (post.freq > this.freq)。
    DoublyLinkedList post;
    // 该双向链表的头节点，新节点从头部加入，表示最近访问。
    Node head;
    // 该双向链表的尾节点，删除节点从尾部删除，表示最久访问。
    Node tail;
    
    // 封装存储对应访问频次节点的双向链表。
    public DoublyLinkedList() {
        head = new Node();
        tail = new Node();
        head.post = tail;
        tail.pre = head;
    }
    
    public DoublyLinkedList(int freq) {
        head = new Node();
        tail = new Node();
        head.post = tail;
        tail.pre = head;
        this.freq = freq;
    }
    
    void removeNode(Node node) {
        node.pre.post = node.post;
        node.post.pre = node.pre;
    }
    
    void addNode(Node node) {
        node.post = head.post;
        head.post.pre = node;
        head.post = node;
        node.pre = head;
        node.doublyLinkedList = this;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```