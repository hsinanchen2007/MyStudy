### 解题思路
此处撰写解题思路

### 代码

```java
class LFUCache {
    private Map<Integer, Node> map;
    private Map<Integer, DLList> freqMap;
    private int size;
    private int capacity;
    private int minAge;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>(capacity);
        this.freqMap = new HashMap<>(capacity);
        minAge = 0;
    }
    
    public int get(int key) {
        Node n = map.get(key);
        if(n != null) {
            remove(n);
            n.freq++;
            // System.out.println("n.freq:" + n.freq + ", key:" + key + ", minAge:" + minAge);
            add(n);

            return n.val;
        } else {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        if(this.capacity < 1) {
            return;
        }

        Node n = map.get(key);
        if(n != null) {
            remove(n);

            n.freq++;
            n.val = value;

            add(n);
        } else {
            if(size >= this.capacity) {
                //System.out.println("minAge:" + minAge);
                DLList freqList = freqMap.get(minAge);

                if(freqList != null) {
                    Node n1 = freqList.tail.pre;
                    map.remove(n1.key);
                    --size;
                    freqList.removeNode(n1);
                    if(freqList.isEmpty()) {
                        freqMap.remove(key);
                        // minAge += 1;
                    }
                }
            }

            Node newNode = new Node(key, value, 1);
            map.put(key, newNode);
            ++size;

            minAge = 1;
            DLList freqList = freqMap.get(minAge);
            if(freqList == null) {
                freqList = new DLList();
                freqMap.put(minAge, freqList);
            }

            freqList.addNode(newNode);
        }
    }

    public void remove(Node n) {
        int freq = n.freq;
        DLList freqList = freqMap.get(freq);
        //System.out.println(" remove key:" + n.key + ", freq:" + freq + ", freqList is null:" + (freqList == null));
        if(freqList != null) {
            freqList.removeNode(n);

            if(freqList.isEmpty()) {
                //System.out.println("key:" + n.key + ", freq:" + freq + ", freq list is empty");
                freqMap.remove(freq);
                // 最小频率的列表空时才需要更新为新的最小频次，方便下次淘汰缓存
                if(freq == minAge) {
                    minAge += 1;
                }
            }
        }
    }

    public void add(Node n) {
        int freq = n.freq;

        DLList freqList = freqMap.get(freq);
        if(freqList == null) {
            freqList = new DLList();
            freqMap.put(freq, freqList);
        } 

        //System.out.println("freq:" + freq);
        freqList.addNode(n);
    }

    class Node  {
        private int key;
        private int val;
        private int freq;
        Node pre;
        Node next;

        public Node(int key, int val, int freq) {
            this.key = key;
            this.val = val;
            this.freq = freq;
        }
    }

    class DLList {
        Node head = new Node(0, 0, 0);
        Node tail = new Node(0, 0, 0);

        public DLList() {
            head.next = tail;
            head.pre = tail;
            tail.pre = head;
            tail.next = head;
        }

        public boolean isEmpty() {
            return head.next == tail;
        }

        public void addNode(Node n) {
            n.next = head.next;
            n.pre = head;
            head.next = n;
            n.next.pre = n;

            //System.out.println("addNode head.next:" + head.next.key);
        }

        public void removeNode(Node n) {
            //System.out.println("remove key:" + n.key + ", head.next:" + head.next.key);
            n.next.pre = n.pre;
            n.pre.next = n.next;
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