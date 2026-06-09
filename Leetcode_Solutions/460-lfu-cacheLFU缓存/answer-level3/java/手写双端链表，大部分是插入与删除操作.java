    
    // 双端链表 + 双端链表
    class LFUCache {
        class Node{
            int key, value, count;
            Node pre, next;
            FrequencyList cur;      // 当前value属于哪个频次的list
            public Node() {}
            public Node(int key, int value, int count) {
                this.key = key;
                this.value = value;
                this.count = count;
            }
        }
        
        class FrequencyList{
            int count;
            FrequencyList pre;
            FrequencyList next;
            Node head = new Node();
            Node tail = new Node();
            public FrequencyList(int count) {
                this.count = count;
                head.next = tail;
                tail.pre = head;
            }
        }
        
        HashMap<Integer, Node> cache;
        FrequencyList low;
        FrequencyList high;
        int capacity;
        
        public LFUCache(int capacity) {
            cache = new HashMap<>();
            this.capacity = capacity;
            low = new FrequencyList(-1);
            high = new FrequencyList(-1);
            low.next = high;
            high.pre = low;
        }
        
        public int get(int key) {
            if(cache.isEmpty() || !cache.containsKey(key)) {
                return -1;
            }
            Node node = cache.get(key);
            removeToNextFreq(node);
            return node.value;
        }
        
        // 该node移动到频率链表的下一个频率
        // 空的list要删除
        public void removeToNextFreq(Node node) {
            int count = node.count;
            node.count++;                     // 使用次数++
            FrequencyList cur = node.cur;     // 该node所属的频次list
            removeNode(node);
            FrequencyList nextlist = cur.next;
            if(cur.head.next == cur.tail) {   // 该list为空就删了
                removeList(cur);
            }
            if(nextlist.count == count + 1) {     // 新的放在尾巴一侧，删除就从head侧删即可
                insertNode(node, nextlist.tail);  // insert node
                node.cur = nextlist;
            }else {
                FrequencyList list = new FrequencyList(count + 1);
                insertList(list, nextlist);       // insert list
                insertNode(node, list.head.next); // insert Node
                node.cur = list;
            }
        }
        
        // cache满时要删除一个缓存
        public void put(int key, int value) {
            if(capacity == 0) {
                return;
            }
            if(cache.containsKey(key)) {
                Node node = cache.get(key);
                node.value = value;
                removeNode(node);
                removeToNextFreq(node);
            }else {
                if(cache.size() == capacity) {        // 删除一个
                    FrequencyList cur = low.next;
                    cache.remove(cur.head.next.key);
                    removeNode(cur.head.next);
                    if(cur.head.next == cur.tail) {   // 该list为空就删了
                        removeList(cur);
                    }
                }
                Node node = new Node(key,value, 1);
                cache.put(key, node);
                if(low.next == high || low.next.count != 1) {
                    FrequencyList list = new FrequencyList(1);
                    insertList(list, low.next);       // insert list
                    insertNode(node, list.tail);      // insert node
                    node.cur = list;
                }else {
                    insertNode(node, low.next.tail);  // insert node
                    node.cur = low.next;
                }
            }
        }
        
        public void insertNode(Node front, Node after) {
            front.next = after;
            front.pre = after.pre;
            after.pre.next = front;
            after.pre = front;
        }
        
        public void insertList(FrequencyList front, FrequencyList after) {
            front.next = after;
            front.pre = after.pre;
            after.pre.next = front;
            after.pre = front;
        }
        
        public void removeList(FrequencyList cur) {
            cur.next.pre = cur.pre;
            cur.pre.next = cur.next;
        }
        
        public void removeNode(Node node) {
            node.next.pre = node.pre;
            node.pre.next = node.next;
        }
        
    }