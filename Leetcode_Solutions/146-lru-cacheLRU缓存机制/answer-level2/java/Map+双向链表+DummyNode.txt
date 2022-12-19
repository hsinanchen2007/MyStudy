### 解题思路
Map用于快速查找
链表的头节点保存最近访问过的节点，尾节点保存最久访问过的节点，用于淘汰
DummyNode用于规避临界值问题


### 代码

```java
class LRUCache {
    
    private int capacity;
    private int size = 0;
    private Map<Integer, Node> cache = new HashMap<>();
    private Node head = new Node();
    private Node tail = new Node();
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.pre = head;
    }
    
    public int get(int key) {
        
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        
        moveToFirst(node);    
            
        return node.value;
    }
    
    public void put(int key, int value) {
        
        Node node = cache.get(key);
        if (node != null) {
            // update value
            node.value = value;
            
            moveToFirst(node);
        }
        else {
            Node newNode = new Node(key, value);
            
            insertNode(newNode);
            cache.put(key, newNode);
            
            if (++size > capacity) {
                cache.remove(tail.pre.key);
                delete(tail.pre);
                size--;
            }
        }
    }
    
    // 双向链表节点
    class Node {
        int key;
        int value;
        Node pre;
        Node next;
        
        Node() {
            
        }
        
        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }
    
    // 插入一个节点作为双向链表的头节点
    void insertNode(Node node) {
        
        node.next = head.next;
        node.pre = head;
        head.next = node;
        node.next.pre = node;
    }
    
    // 删除双向链表中的一个节点，该节点一定存在
    void delete(Node node) {
        
        Node preNode = node.pre;
        Node nextNode = node.next;
        
        node.pre = null;
        node.next = null;
        
        preNode.next = nextNode;
        nextNode.pre = preNode;
    }
    
    // 将双向链表中的节点移动至表头，该节点一定存在
    void moveToFirst(Node node) {
        
        delete(node);
        insertNode(node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```