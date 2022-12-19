    
    // 使用一条双向链表来做一个cache！，但是时间复杂度为O(n)
    // 使用次数少的在左边（即靠近head），同等次数，时间久的在左边
    // 这样删除的话直接删除左边第一个即可
    class LFUCache {
        class Node{
            int key, value, count;
            Node next, pre;
            public Node() {}
            public Node(int key, int value, int count) {
                this.key = key;
                this.value = value;
                this.count = count;
            }
        }
        
        public HashMap<Integer, Node> cache;   // 存储k / v，只不过v被封装了一下
        public int capacity;
        Node head, tail;
        
        public LFUCache(int capacity) {
            cache = new HashMap<>();
            this.capacity = capacity;
            head = new Node();
            tail = new Node();
            head.next = tail;
            tail.pre = head;
        }
        
        public int get(int key) {
            if(cache.isEmpty() || !cache.containsKey(key)) {
                return -1;
            }
            Node cur = cache.get(key);
            cur.count++;
            removeToNext(cur);
            return cur.value;
        }
        
        public void put(int key, int value) {
            if(capacity == 0) {
                return;
            }
            if(cache.containsKey(key)) {          // cache满不满没影响
                cache.get(key).count++;
                cache.get(key).value = value;
                removeToNext(cache.get(key));
            }else {
                if(cache.size() == capacity) {     // cache满了就先删除一个
                    cache.remove(head.next.key);
                    removeNode(head.next);
                }
                Node node = new Node(key, value, 1);
                cache.put(key, node);
                node.next = head.next;
                node.pre = head;
                head.next = node;
                node.next.pre = node;
                removeToNext(node);    //
            }
        }

        public void removeNode(Node cur) {
            if(cur == head || cur == tail || cur == null) {
                return;
            }
            cur.pre.next = cur.next;
            cur.next.pre = cur.pre;
        }

        // 将使用次数少的node排在head后面（同等次数但很久没使用的也这样排序）
        public void removeToNext(Node cur) {
            Node p = cur.next;
            cur.pre.next = p;
            p.pre = cur.pre;
            // 到达尾巴或者找到第一个count比cur大的
            while(p.count <= cur.count && p != tail) {
                p = p.next;
            }
            cur.next = p;
            cur.pre = p.pre;
            p.pre.next = cur;
            p.pre = cur;
        }
    }