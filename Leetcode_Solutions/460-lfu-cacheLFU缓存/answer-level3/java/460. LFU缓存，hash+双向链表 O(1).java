### 解题思路
#### 思路和数据结构
由于要求 **O(1)** 的复杂度，那么只有用 **hash** 才能满足条件。
**双向链表usedSeq** 按照使用频率存储所有缓存元素，**哈希表frequencyMap** 快速查找 **usedSeq** 里的元素。
* `DoubleLinkedList usedSeq `： 按照使用频率从低到高存储所有元素，当缓存满了以后，删除这个表的表头元素。保证 **put** 操作能在 **O(1)** 的时间内完成。
* `private Map<Integer, Node> map`： key-value 的缓存，value 存在 Node.value 里。保证 **get** 操作能在 **O(1)** 的时间内完成。
* `private Map<Integer, Node> frequencyMap`： 按照使用频率存储缓存里的元素，指向最后一个频率为 cnt 的节点。加快 **get** 操作，保证其能在 **O(1)** 的时间内完成。**如果没有这个 hash，那么更新 usedSeq 可能会变成一个 O(N) 的操作**。

#### 以下是对于一系列操作数据结构的变化示例
```
LFUCache cache = new LFUCache(3 /* capacity (缓存容量) */);

cache.put(1, 1);
cache.put(2, 2);

res.add(cache.get(1)); // 返回 1

cache.put(2, 5);
cache.put(3, 3);

res.add(cache.get(2)); // 5
res.add(cache.get(3)); // 3

cache.put(4, 4);    // 去除 key 1

res.add(cache.get(1)); // -1


res.add(cache.get(3)); // 3
res.add(cache.get(4)); // 4
```

```
put 1:1
LFUCache{capacity=3, size=1, frequencyMap=[1:Node{key=1, val=1, cnt=1} ], usedSeq=[1:1:1]}

put 2:2
LFUCache{capacity=3, size=2, frequencyMap=[1:Node{key=2, val=2, cnt=1} ], usedSeq=[1:1:1<->2:2:1]}

get: 1 ->Node{key=1, val=1, cnt=2}
LFUCache{capacity=3, size=2, frequencyMap=[1:Node{key=2, val=2, cnt=1} 2:Node{key=1, val=1, cnt=2} ], usedSeq=[2:2:1<->1:1:2]}

put 2:5
LFUCache{capacity=3, size=2, frequencyMap=[2:Node{key=2, val=5, cnt=2} ], usedSeq=[1:1:2<->2:5:2]}

put 3:3
LFUCache{capacity=3, size=3, frequencyMap=[1:Node{key=3, val=3, cnt=1} 2:Node{key=2, val=5, cnt=2} ], usedSeq=[3:3:1<->1:1:2<->2:5:2]}

get: 2 ->Node{key=2, val=5, cnt=3}
LFUCache{capacity=3, size=3, frequencyMap=[1:Node{key=3, val=3, cnt=1} 2:Node{key=1, val=1, cnt=2} 3:Node{key=2, val=5, cnt=3} ], usedSeq=[3:3:1<->1:1:2<->2:5:3]}

get: 3 ->Node{key=3, val=3, cnt=2}
LFUCache{capacity=3, size=3, frequencyMap=[2:Node{key=3, val=3, cnt=2} 3:Node{key=2, val=5, cnt=3} ], usedSeq=[1:1:2<->3:3:2<->2:5:3]}

put 4:4
LFUCache{capacity=3, size=3, frequencyMap=[1:Node{key=4, val=4, cnt=1} 2:Node{key=3, val=3, cnt=2} 3:Node{key=2, val=5, cnt=3} ], usedSeq=[4:4:1<->3:3:2<->2:5:3]}

get: 1 ->null
LFUCache{capacity=3, size=3, frequencyMap=[1:Node{key=4, val=4, cnt=1} 2:Node{key=3, val=3, cnt=2} 3:Node{key=2, val=5, cnt=3} ], usedSeq=[4:4:1<->3:3:2<->2:5:3]}

get: 3 ->Node{key=3, val=3, cnt=3}
LFUCache{capacity=3, size=3, frequencyMap=[1:Node{key=4, val=4, cnt=1} 3:Node{key=3, val=3, cnt=3} ], usedSeq=[4:4:1<->2:5:3<->3:3:3]}

get: 4 ->Node{key=4, val=4, cnt=2}
LFUCache{capacity=3, size=3, frequencyMap=[2:Node{key=4, val=4, cnt=2} 3:Node{key=3, val=3, cnt=3} ], usedSeq=[4:4:2<->2:5:3<->3:3:3]}
```
### 代码（使用frequencyMap辅助查找，21ms）
```java
class LFUCache {
     private int capacity;
    private int size;
    private DoubleLinkedList usedSeq = new DoubleLinkedList();
    private Map<Integer, Node> map;
    // 指向最后一个为 frequency 的节点
    private Map<Integer, Node> frequencyMap;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.map = new HashMap<>();
        this.frequencyMap = new HashMap<>();
    }

    public int get(int key) {
        Node node = getNode(key);
        if (node == null) return -1;
        return node.val;
    }

    private Node getNode(int key) {
        Node node = map.get(key);
        if (node == null) return null;

        deleteFromFrequencyMap(node);
        node.cnt++;
        addToFrequencyMap(node);

        return node;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;
        Node node = getNode(key);
        if (node != null) {
            node.val = value;
            return;
        }

        if (size == capacity) {
            deleteLFUNode();
        }

        node = new Node(key, value, 1, null, null);
        addToFrequencyMap(node);
        this.map.put(key, node);
        ++size;
    }

    private void deleteLFUNode() {
        if (!usedSeq.isEmpty()) {
            Node delNode = usedSeq.head;
            deleteFromFrequencyMap(delNode);
            map.remove(delNode.key);
            --size;
        }
    }

    private void addToFrequencyMap(Node node) {
        Node curCntTail = frequencyMap.get(node.cnt);
        if (curCntTail == null) {
            Node preCntTail = frequencyMap.get(node.cnt - 1);
            Node preNode = node.pre;
            if (preCntTail == null) {
                usedSeq.addNode(preNode, node);
            } else {
                usedSeq.addNode(preCntTail, node);
            }
        } else {
            usedSeq.addNode(curCntTail, node);
        }
        frequencyMap.put(node.cnt, node);
    }

    private void deleteFromFrequencyMap(Node node) {
        usedSeq.removeNode(node);
        Node frequencyTail = frequencyMap.get(node.cnt);
        if (frequencyTail == node) {
            Node preNode = node.pre;
            if (preNode == null || preNode.cnt != node.cnt) {
                frequencyMap.remove(node.cnt);
            } else {
                frequencyMap.put(node.cnt, preNode);
            }
        }
    }

    private class DoubleLinkedList {
        Node head;
        Node tail;

        public DoubleLinkedList() {
            this.head = null;
            this.tail = null;
        }

        /**
         * 把 node 插入到 insertPos 之后，如果 insertPos 为 null，那么插到链表头
         *
         * @param insertPos
         * @param node
         */
        public void addNode(Node insertPos, Node node) {
            node.pre = insertPos;
            if (insertPos == null) { // 插头部
                node.next = head;
                if (head != null) {
                    head.pre = node;
                }
                head = node;
            } else { //
                node.next = insertPos.next;
                insertPos.next = node;
                if (node.next != null) {
                    node.next.pre = node;
                }
            }

            if (node.next == null) {
                tail = node;
            }
        }

        public void removeNode(Node node) {
            if (node.pre != null) {
                node.pre.next = node.next;
            } else {
                head = node.next;
            }
            if (node.next != null) {
                node.next.pre = node.pre;
            } else {
                tail = node.pre;
            }
        }

        public boolean isEmpty() {
            return head == null ? true : false;
        }

        @Override
        public String toString() {
            StringBuilder stringBuilder = new StringBuilder();
            Node p = head;
            stringBuilder.append("[");
            int cnt = 0;
            // check head.pre
            if (p.pre != null) {
                stringBuilder.append(p.pre.key + "<-");
            }
            while (p != null) {
                stringBuilder.append(p.key + ":" + p.val + ":" + p.cnt);
                // check if p.next.pre equals p
                if (p.next != null) {
                    if (p.next.pre == p) {
                        stringBuilder.append("<->");
                    } else {
                        stringBuilder.append("->");
                    }
                } else { // check tail
                    if (p != tail) {
                        stringBuilder.append(" tail=" + tail);
                        throw new IllegalStateException("tail not match");
                    }
                }
                p = p.next;
                ++cnt;
                if (cnt > 20) break;
            }
            stringBuilder.append("]");

            return stringBuilder.toString();
        }
    }

    private class Node {
        int key;
        int val;
        int cnt;
        Node pre;
        Node next;

        public Node(int key, int val, int cnt, Node pre, Node next) {
            this.key = key;
            this.val = val;
            this.cnt = cnt;
            this.pre = pre;
            this.next = next;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "key=" + key +
                    ", val=" + val +
                    ", cnt=" + cnt + "}";
        }
    }
}
```

### 代码（没有使用frequencyHash辅助查找，142ms）
``` java
class LFUCache {
    int capacity;
    int size;
    DoubleLinkedList usedSeq = new DoubleLinkedList();
    // 新节点插入的位置
    Node insertPos;
    Map<Integer, Node> map;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.map = new HashMap<>();
    }

    public int get(int key) {
        Node node = getNode(key);
        if (node == null) return -1;
        return node.val;
    }

    private Node getNode(int key) {
        Node node = map.get(key);
        if (node == null) return null;
        node.cnt++;
        if (node.cnt == 2) {
            if (node.pre != null && node.pre.cnt == 1) {
                insertPos = node.pre;
            } else {
                insertPos = null;
            }
        }
        // 往后移动
        while (node.next != null && node.cnt >= node.next.cnt) {
            usedSeq.moveToTail(node);
            if (node.pre.cnt == 1) {
                insertPos = node.pre;
            }
        }
        return node;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;
        Node node = getNode(key);
        if (node != null) {
            node.val = value;
            return;
        }

        if (size == capacity) {
            deleteLFUNode();
        }

        node = new Node(key, value, null, null);
        usedSeq.addNode(insertPos, node);
        insertPos = node;

        this.map.put(key, node);
        ++size;
    }

    private void deleteLFUNode() {
        if (!usedSeq.isEmpty()) {
            Node delNode = usedSeq.removeHead();
            if (insertPos != null && delNode.key == insertPos.key) {
                insertPos = delNode.pre;
            }
            map.remove(delNode.key);
            --size;
        }
    }

    private class DoubleLinkedList {
        Node head;

        public DoubleLinkedList() {
            this.head = null;
        }

        /**
         * 把 node 插入到 insertPos 之后，如果 insertPos 为 null，那么插到链表头
         * @param insertPos
         * @param node
         */
        public void addNode(Node insertPos, Node node) {
            node.pre = insertPos;
            if (insertPos == null) { // 插头部
                addToHead(node);
            } else { //
                node.next = insertPos.next;
                insertPos.next = node;
                if (node.next != null) {
                    node.next.pre = node;
                }
            }
        }

        /**
         * 把 node 插入到链表头
         * @param node
         */
        public void addToHead(Node node) {
            node.next = head;
            if (head != null) {
                head.pre = node;
            }
            head = node;
        }

        public Node removeHead() {
            Node node = head;

            if (head != null) {
                head = head.next;
                if (head != null) {
                    head.pre = null;
                }
            }
            return node;
        }

        /**
         * 把 node 朝着链表尾部移动一步
         * @param node
         */
        public void moveToTail(Node node) {
            Node nextNode = node.next;
            // update pre point
            if (node.pre == null) { //表头
                node.pre = nextNode;
                nextNode.pre = null;
                head = nextNode;
            } else {
                nextNode.pre = node.pre;
                node.pre.next = nextNode;
                node.pre = nextNode;
            }

            // update next point
            node.next = nextNode.next;
            if (nextNode.next != null) {
                nextNode.next.pre = node;
            }
            nextNode.next = node;
        }

        public void removeNode(Node node) {
            if (node.pre == null) { // 表头
                head = node.next;
                node.next.pre = null;
            } else {
                node.pre.next = node.next;
                node.next.pre = node.pre;
            }
        }

        public boolean isEmpty() {
            return head == null? true: false;
        }
    }

    private class Node {
        int key;
        int val;
        int cnt;
        Node pre;
        Node next;

        public Node(int key, int val, Node pre, Node next) {
            this.key = key;
            this.val = val;
            this.cnt = 1;
            this.pre = pre;
            this.next = next;
        }
    }

}
```