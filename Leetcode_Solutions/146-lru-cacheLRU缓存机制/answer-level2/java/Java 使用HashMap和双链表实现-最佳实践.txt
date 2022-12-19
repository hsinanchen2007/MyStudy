LRUCache最简单的实现是单链表
- get元素时，同时将该元素移动到链表尾部
- put元素时，先查找
- 如果没有找到，直接移动到链表尾部
- 如果找到了，移除原来元素，将新元素插入链表尾部
- 如果Cache已满，移除链表头结点

这种做法时间复杂度太高，为O(n),题目要求使用时间复杂度O(1)完成，符合这个条件的只有哈希表,所以最终的答案就是HashMap+双向链表

Java中LinkedHashMap就是这种结构，但是我们还是决定使用HashMap+双链表实现一个LRUCache，这样对LinkedHashMap这种结构也有了更深的了解

__为什么使用双链表，双链表保存了前驱和后继指针，方便在O(1)的时间复杂度移除元素__

LRUCache中保存了一下几个变量
- HashMap<Integer,Integer> map   保存Node，保证在O(1)的时间复杂度定位到元素位置
- Node head  双链表的头部，最近没有被访问的元素，Cache满时，移除head元素
- Node tail  双链表的尾部，所有最近访问的元素都放到尾部
- int size  当前LRUCache共有多少元素
- int capacity  当前LRUCache最大大小

```
public class LRUCache {
    private int size;
    private int capacity;
    private HashMap<Integer, Node> map;
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        map = new HashMap<>(capacity, 0.75F);
    }

    public int get(int key) {
        Node node = getNode(key);
        return node == null ? -1 : node.value;
    }

    private Node getNode(int key) {
        Node node = map.get(key);
        if (node == null) return null;

        if (tail != node) {
            if (head == node) {
                head = node.next;
                head.prev = null;
            } else {
                node.prev.next = node.next;
                node.next.prev = node.prev;
            }
            appendTail(node);
        }

        return node;
    }

    private void trimToSize() {
        while (size > capacity) {
            Node prev = head;
            head = head.next;
            head.prev = null;
            size--;
            map.remove(prev.key);
        }
    }

    public void put(int key, int value) {
        Node node = new Node(key, value);
        Node prev = getNode(key);

        if (prev == null) {
            map.put(key, node);
            appendTail(node);
            size++;
            trimToSize();
        } else {
            prev.value = value;
        }
    }

    private void appendTail(Node node) {
        if (size == 0) {
            head = tail = node;
        } else {
            node.prev = tail;
            tail.next = node;
            node.next = null;
            tail = node;
        }
    }

    class Node {
        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }

        int key;
        int value;
        Node next;
        Node prev;
    }
}
```