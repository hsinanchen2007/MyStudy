    
    // O(1)时间复杂度的实现
    class LFUCache {
        class Node {
            int key, value, count;
            public Node() {}
            public Node(int key, int value, int count) {
                this.key = key;
                this.value = value;
                this.count = count;
            }
        }
        
        public HashMap<Integer, Node> hm;          // k / v ，这里的key为传入的key
        public HashMap<Integer, LinkedHashSet<Node>> lhm;   // 这里的key为使用频率
        public int capacity;
        public int min;      //记录最小访问次数
        
        public LFUCache(int capacity) {
            hm = new HashMap<>();
            lhm = new HashMap<>();
            this.capacity = capacity;
            min = 0;
        }
        
        public int get(int key) {
            if(hm.isEmpty() || !hm.containsKey(key)) {
                return -1;
            }
            Node node = hm.get(key);
            removeToNext(node);
            return node.value;
        }

        // 要考虑淘汰缓存
        public void put(int key, int value) {
            if(capacity == 0) {
                return;
            }
            if(hm.containsKey(key)) {
                Node node = hm.get(key);
                node.value = value;
                removeToNext(node);
            }else {
                // 开始删除一个缓存
                if(hm.size() == capacity) {
                    // linkedhashset是排好序的，默认排序就是先插入的先出来（就是时间最久的先出来）
                    Node node = lhm.get(min).iterator().next();
                    hm.remove(node.key);
                    lhm.get(min).remove(node);
                }
                Node newNode = new Node(key, value, 1);
                hm.put(key, newNode);
                min = 1;                  // 新加入节点时，最小使用次数就是1
                if(lhm.get(1) == null) {
                    lhm.put(1, new LinkedHashSet<Node>());
                }
                lhm.get(1).add(newNode);
            }
        }
        
        // 将该Node移动到下一个频率
        public void removeToNext(Node node) {
            int count = node.count;
            lhm.get(count).remove(node);
            node.count++;
            if(lhm.get(count + 1) == null) {
                lhm.put(count + 1, new LinkedHashSet<Node>());
            }
            lhm.get(count + 1).add(node);
            if(min == count && lhm.get(count).isEmpty()) {
                min += 1;
            }
        }
    }