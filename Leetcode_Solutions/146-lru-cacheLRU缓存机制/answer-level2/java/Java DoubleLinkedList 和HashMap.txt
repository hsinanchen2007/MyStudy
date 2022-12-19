### 解题思路
思路是维持一个双向链表和一个hashmap，hashmap用于快速查找元素，双向链表用于维持顺序。

### 代码

```java
class LRUCache {
    int size;
    int capacity;
    LinkedNode head;
    LinkedNode tail;
    HashMap<Integer, LinkedNode> map = new HashMap<>();
    public LRUCache(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        head = new LinkedNode();
        tail = new LinkedNode();
        head.pre = null;
        tail.next = null;
        head.next = tail;
        tail.pre = head;
    }
    
    public int get(int key) {
        LinkedNode val = map.get(key);
        if (val != null) {
            moveTohead(val);
            return val.value;
        } 
        return -1;
    }
    
    public void put(int key, int value) {
        

        LinkedNode node = map.get(key);
        if (node != null) {
            node.value = value;
            moveTohead(node);
            return;
        }
        node = new LinkedNode();
        node.key = key;
        node.value = value;
        map.put(key, node);
        addNode(node);
        size ++;
        
        if (size > capacity) {
            LinkedNode remove = this.removeTail();
            map.remove(remove.key);
            size --;
        }
        LinkedNode ln = head.next;
    }

    void addNode(LinkedNode node) {
        node.pre = head;
        node.next = head.next;
        head.next = node;
        node.next.pre = node;
    }

    void removeNode(LinkedNode node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }

    void moveTohead(LinkedNode node) {
        removeNode(node);
        addNode(node);
    }

    LinkedNode removeTail() {
        LinkedNode remove = tail.pre;
        removeNode(remove);
        return remove;
    }
}

class LinkedNode {
    int key;
    int value;
    LinkedNode pre;
    LinkedNode next;
}
```