LRU一般实现都是双向链表实现。
我是用单向链表实现，这样存储的话会比双向链表节省部分空间，但是就在操作的时候会稍微麻烦一点，其实就是多一种思路而已。
这种实现方式hashMap存储的是每一个key前一个链表节点：
```
class LRUCache {

        private Map<Integer, ListNode> keyPrevListNode;
        private int capacity;
        private int size = 0;
        private ListNode head = new ListNode(0,0);
        private ListNode tail = null;

        public LRUCache(int capacity) {
            this.capacity = capacity;
            this.keyPrevListNode = new HashMap<>(capacity);
        }

        public int get(int key) {
            if (!keyPrevListNode.containsKey(key)) {
                return -1;
            }
            ListNode prevNode = keyPrevListNode.get(key);
            ListNode valueNode = prevNode.next;
            convertNode(prevNode, valueNode);
            return valueNode.val;
        }

        public void put(int key, int value) {
            ListNode prevNode = keyPrevListNode.get(key);
            if (prevNode != null) {
                ListNode valueNode = prevNode.next;
                convertNode(prevNode, valueNode);
                valueNode.val = value;
            } else {
                if (size == capacity) {
                    ListNode tailPrevNode = keyPrevListNode.get(tail.key);
                    keyPrevListNode.remove(tail.key);
                    tail = tailPrevNode;
                    tailPrevNode.next = null;
                    if (tail == head) {
                        tail = null;
                    }
                } else {
                    size++;
                }
                ListNode newNode = new ListNode(key, value);
                newNode.next = head.next;
                ListNode next = head.next;
                if (next != null) {
                    keyPrevListNode.put(next.key, newNode);
                }
                head.next = newNode;
                keyPrevListNode.put(key, head);
                if (tail == null) {
                    tail = newNode;
                }
            }
        }

        private void convertNode(ListNode prevNode, ListNode valueNode) {
            if (prevNode == head) {
                return;
            }
            if (tail == valueNode) {
                tail = prevNode;
            }
            prevNode.next = valueNode.next;
            ListNode valueNodeNext = valueNode.next;
            if (valueNodeNext != null) {
                keyPrevListNode.put(valueNodeNext.key, prevNode);
            }
            ListNode next = head.next;
            if (next != null) {
                keyPrevListNode.put(next.key, valueNode);
            }
            valueNode.next = head.next;
            head.next = valueNode;
            keyPrevListNode.put(valueNode.key, head);
        }

        private class ListNode {
            int key;
            int val;
            ListNode next;

            public ListNode(int key, int val) {
                this.key = key;
                this.val = val;
            }
        }
    }
```
