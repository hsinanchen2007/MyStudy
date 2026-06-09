解题思路简单描述：
- 使用HashMap来实现元素的查找，HashMap的Key为Integer，Value为自定义Node，节点值为待缓存的值。
- 使用自定义双向链表来维护LRU Cache中各个元素的使用情况，链表元素按照最近使用先后顺序排列。
- 使用头结点和尾结点来方便双向链表的插入、删除操作。
- 读取元素时，如果该元素存在，那么更新双向链表，将该元素对应的节点调整至表头。插入元素时，如果该元素存在，那么更新该元素对应的节点的值并将其调整至表头，如果该元素不存在，那么创建新节点并将其插入表头。在插入元素之前判断缓存容量，如果已达到上限，那么先逐出列表尾部的元素节点后再插入。

```
class LRUCache {
    private int capacity;

    private Map<Integer, Node> items;

    // 头结点与尾结点。
    private Node head;
    private Node tail;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.items = new HashMap<Integer, Node>();

        initializeLinkedList();
    }

    private void initializeLinkedList() {
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        
        this.head.prev = null;
        this.head.next = this.tail;
        
        this.tail.prev = this.head;
        this.tail.next = null;
    }
    
    public int get(int key) {
        Node node = this.items.get(key);
        if (node == null) {
            return -1;
        }

        updateRecentlyUsedNode(node);

        return node.value;
    }
    
    public void put(int key, int value) {
        Node node = this.items.get(key);
        if (node != null) {
            node.value = value;

            updateRecentlyUsedNode(node);
        } else {
            node = new Node(key, value);

            if (this.items.size() >= this.capacity) {
                // 判断缓存容量，如果已达到上限，那么就逐出尾部节点。
                evictLastNode();  
            }

            this.items.put(key, node);

            insertAsFirstNode(node);
        }
    }

    private void updateRecentlyUsedNode(Node node) {
        // 先将该节点从双向链表中移除。
        node.prev.next = node.next;
        node.next.prev = node.prev;

        // 将该节点调整至表头。
        insertAsFirstNode(node);
    }
    
    private void insertAsFirstNode(Node node) {
        node.next = this.head.next;
        this.head.next.prev = node;

        this.head.next = node;
        node.prev = this.head;
    }
     
    private void evictLastNode() {
        Node nodeToEvict = this.tail.prev;
        
        this.items.remove(nodeToEvict.key);

        nodeToEvict.prev.next = this.tail;
        this.tail.prev = nodeToEvict.prev;
    }

    private class Node {
        private int key;
        private int value;

        private Node prev;
        private Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }
}
```
