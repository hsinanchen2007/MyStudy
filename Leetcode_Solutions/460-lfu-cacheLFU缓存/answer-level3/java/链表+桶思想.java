### 解题思路

这题的重点就在于你把相同的count 的节点放到一个桶里，然后用把桶按照从小到大进行双向连接。
桶主要是为了移除节点方便。


### 代码

```java
class LFUCache {

   private int capacity;
    
    private int size;

    private HashMap<Integer, Node> keyMapNode;

    private HashMap<Node, Bucket> nodeMapBucket;

    /* the first bucket.   */
    private Bucket headBucket; // the

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.keyMapNode = new HashMap<>();
        this.nodeMapBucket = new HashMap<>();
        this.headBucket = null;
    }

    public int get(int key) {
        Node node  = keyMapNode.get(key);
        if (node == null) {
            return -1;
        }
        node.count++;
        moveNodeToNextBucket(node, nodeMapBucket.get(node));
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (keyMapNode.containsKey(key)) {
            Node node = keyMapNode.get(key);
            node.value = value;
            node.count++;
            moveNodeToNextBucket(node, nodeMapBucket.get(node));
        } else {
            if (size == capacity) {
                Node deleteNode = headBucket.tail;
                headBucket.deleteNode(deleteNode);
                checkBucket(headBucket);
                keyMapNode.remove(deleteNode.key);
                nodeMapBucket.remove(deleteNode);
                size--;
            }
            Node newNode = new Node(key, value, 1);
            if (headBucket == null) {
                headBucket = new Bucket(newNode);
            } else {
                if (headBucket.head.count.equals(newNode.count)) {
                    headBucket.addNodeFromHead(newNode);
                } else {
                    Bucket newBucket = new Bucket(newNode);
                    newBucket.right = headBucket;
                    headBucket.left = newBucket;
                    headBucket = newBucket;
                }
            }
            this.keyMapNode.put(key, newNode);
            this.nodeMapBucket.put(newNode, headBucket);
            this.size++;
        }
    }

    /**
     * false: bucket delete node;
     * true: bucket is empty.
     * @param bucket
     * @return
     */
    private boolean checkBucket(Bucket bucket) {
        if (!bucket.isEmpty()) {
            return false;
        }
        if (headBucket == bucket) {
            if (headBucket.right == null) {
                headBucket = null;
            } else {
                headBucket = bucket.right;

                // move headBucket left node;
                headBucket.left = null;
            }
        } else {
            bucket.left.right = bucket.right;
            if (bucket.right != null) {
                bucket.right.left = bucket.left;
            }
        }
        return true;
    }

    /**
     *
     * @param node
     * @param oldBucket
     * @return
     */
    private void moveNodeToNextBucket(Node node, Bucket oldBucket) {
       oldBucket.deleteNode(node);
       Bucket preBucket = oldBucket.left;
       // old Bucket is empty.
       if (!checkBucket(oldBucket)) {
           preBucket = oldBucket;
       }

       Bucket nextBucket = oldBucket.right;
       // next bucket is null.
       if (nextBucket == null) {
           Bucket newBucket = new Bucket(node);
           //
           if (preBucket != null) {
               preBucket.right = newBucket;
           }
           newBucket.left = preBucket;
           if (this.headBucket == null) {
               this.headBucket = newBucket;
           }
           this.nodeMapBucket.put(node, newBucket);
       // exist next bucket
       } else {
           //  nextBucket's count equals node's count
           if (nextBucket.head.count.equals(node.count)) {
               nextBucket.addNodeFromHead(node);
               this.nodeMapBucket.put(node, nextBucket);
           // not equals, make new Bucket.
           } else {
               Bucket tempNewBucket = new Bucket(node);
               if (preBucket != null) {
                   preBucket.right = tempNewBucket;
               }
               tempNewBucket.left = preBucket;
               tempNewBucket.right = nextBucket;
               nextBucket.left = tempNewBucket;
               if (headBucket == nextBucket) {
                   headBucket = tempNewBucket;
               }
               this.nodeMapBucket.put(node, tempNewBucket);
           }
       }
    }

    private class Node {
        public Integer key;
        public Integer value;
        public Integer count;
        public Node pre;
        public Node next;
        public Node(int k, int v, int count) {
            this.key = k;
            this.value = v;
            this.count = count;
        }
    }

    private class Bucket {
        public Node head;
        public Node tail;
        public Bucket left;
        public Bucket right;

        public Bucket(Node node) {
            this.head = node;
            this.tail = node;
        }

        /**
         * 增加桶的头节点
         * @param newHead
         */
        public void addNodeFromHead(Node newHead) {
            newHead.next = head;
            head.pre = newHead;
            head = newHead;
        }


        public boolean isEmpty() {
            return head == null;
        }

        public void deleteNode(Node node) {
            if (head == tail) {
                head = null;
                tail = null;
            } else {
                if (node == head) {
                    head = node.next;
                    head.pre = null;
                } else if (node == tail) {
                    tail = tail.pre;
                    tail.next = null;
                } else {
                    node.pre.next = node.next;
                    node.next.pre = node.pre;
                }
            }
            node.pre = null;
            node.next = null;
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```