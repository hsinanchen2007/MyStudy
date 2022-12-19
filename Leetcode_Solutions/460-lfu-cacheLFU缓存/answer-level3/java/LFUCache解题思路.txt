### 解题思路
利用map和双头链表来解决

### 代码

```java
import java.util.HashMap;
import java.util.Map;

/**
 * @description:
 * @author: 李哲操
 * @create: 2020-04-05 21:39
 **/
class LFUCache {
    private Map<Integer, Node> map;
    private int capacity;
    private int num;
    private Node head;


    public LFUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        num = 0;
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            return getAndMove(key).getValue();
        }
        return -1;
    }

    private Node getAndMove(int key) {
        Node node = map.get(key);
        int count = node.getCount() + 1;
        node.setCount(count);
        move(node);
        return node;
    }

    private void move(Node node) {
        while (null != node.next && node.getCount() >= node.next.getCount()) {
            Node next = node.next;
            Node pre = node.pre;
            Node second = next.next;

            // head也要移动
            if (head == node) {
                head = next;
            }

            if (null != pre) {
                pre.next = next;
            }
            next.pre = pre;
            node.pre = next;
            next.next = node;

            node.next = second;
            if (null != second) {
                second.pre = node;
            }
        }
    }

    public void put(int key, int value) {
        //边界处理
        if (capacity <= 0) {
            return;
        }

        if (map.containsKey(key)) {
            Node node = getAndMove(key);
            node.setValue(value);
        } else {
//            move(node);
            // TODO:边界
            if (num == capacity) {
                map.remove(head.getKey());
                head = head.next;
                if (null != head) {
                    head.pre = null;
                }
            } else {
                num ++;
            }
            Node node = new Node(head, null, 1, key, value);
            // 第一次插入
            if (null != head) {
                head.pre = node;
            }
            head = node;
            map.put(key, node);
            // 新插入的也要move
            move(node);
        }
    }

    class Node {
        private Node next;
        private Node pre;
        private int count;
        private int key;
        private int value;

        public Node(Node next, Node pre, int count, int key, int value) {
            this.next = next;
            this.pre = pre;
            this.count = count;
            this.key = key;
            this.value = value;
        }

        public int getKey() {
            return key;
        }

        public void setKey(int key) {
            this.key = key;
        }

        public Node getPre() {
            return pre;
        }

        public void setPre(Node pre) {
            this.pre = pre;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }

        public int getCount() {
            return count;
        }

        public void setCount(int count) {
            this.count = count;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }
    }

//    public static void main(String[] args) {
//        LFUCache cache = new LFUCache( 3 /* capacity (缓存容量) */ );
//
//        cache.put(1, 1);
//        cache.put(2, 2);
//        cache.put(3, 3);
//        cache.put(4, 4);
//        System.out.println(cache.get(4));       // 返回 4
//        System.out.println(cache.get(3));       // 返回 3
//        System.out.println(cache.get(2));       // 返回 2
//        System.out.println(cache.get(1));       // 返回 -1
//
//        cache.put(5, 5);    // 去除 key 2
//        System.out.println(cache.get(1));       // 返回 -1
//        System.out.println(cache.get(2));       // 返回 2
//        System.out.println(cache.get(3));       // 返回 3
//        System.out.println(cache.get(4));       // 返回 -1
//        System.out.println(cache.get(5));       // 返回 5
//    }
}

```