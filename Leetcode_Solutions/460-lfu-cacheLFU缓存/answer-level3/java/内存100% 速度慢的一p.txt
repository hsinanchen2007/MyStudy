### 解题思路
写了俩小时
官解O(1)基本是下面的优化版，优化了两个点：
1. 链表分段存入HashMap, 这样省去了查找各分值端的端头
2. 单向变双向链表，表尾淘汰，表头新增，否则像下解要找到每个分值的最后一个节点
### 代码

```java
class LFUCache {

    private HashMap<Integer, Integer> cache;
    private int capacity, pos;
    private Node scores;
    private static class Node {
        public int key, score;
        public Node next;
        public Node(int key) {
            this.key = key;
            score = 1;
        }
    }

    public LFUCache(int capacity) {
        this.capacity = capacity;
        cache = new HashMap<>(capacity);
        pos = 0;

    }

    public int get(int key) {
        Integer ret = cache.get(key);
        if (ret == null) return -1;
        inc(key);
        return ret;
    }

    private void inc(int key) {
        if (scores == null) {
            scores = new Node(key);
        } else {
            Node p = scores, pre = null;
            while (p != null && p.key != key) {
                pre = p;
                p = p.next;
            }
            p.score ++;
            if (pre != null) {
                pre.next = p.next;
            } else {
                scores = p.next;
                pre = p;
            }
            while (pre.next != null && pre.next.score <= p.score) {
                pre = pre.next;
            }
            insertAfter(p, pre);
        }
    }

    public void put(int key, int value) {
        if (capacity == 0) return;
        int cur = get(key);
        if (cur == -1) {
            if (pos >= capacity)
                evict();
            else
                pos ++;
            newNode(key);
        }
        cache.put(key, value);
    }

    private void newNode(int key) {
        Node newNode = new Node(key);
        if (scores == null) {
            this.scores = newNode;
        } else {
            if (scores.score > 1) {
                newNode.next = scores;
                scores = newNode;
                return;
            }
            Node p = scores;
            while (p.next != null && p.next.score <= 1) {
                p = p.next;
            }
            insertAfter(newNode, p);
        }
    }

    private void insertAfter(Node newNode, Node p) {
        if (p == newNode)
            scores = p;
        Node next = p.next;
        p.next = newNode;
        newNode.next = next;
    }

    private void evict() {
        cache.remove(scores.key);
        scores = scores.next;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```