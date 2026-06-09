    // 用Node封装信息，k/v，时间戳，操作次数
    class LFUCache {
        class Node{
            int key;
            int value;
            int cnt;
            int time;
            public Node(int key, int value, int cnt, int time) {
                this.key = key;
                this.cnt = cnt;
                this.time = time;
                this.value = value;
            }
        }
        
        public HashMap<Integer, Node> hm;
        public TreeSet<Node> ts;
        public int time;
        public int capacity;
        
        public LFUCache(int capacity) {
            this.capacity = capacity;
            time = 0;
            hm = new HashMap<>();
            ts = new TreeSet<>(new Comparator<Node>() {
                @Override
                public int compare(Node o1, Node o2) {
                    // 如果使用次数相等的话，时间最久的删除（即时间戳最小的那个）
                    return o1.cnt != o2.cnt ? o1.cnt - o2.cnt : o1.time - o2.time;
                }
            });
        }
        
        public int get(int key) {
            if(!hm.containsKey(key) || capacity == 0) {
                return -1;
            }
            Node node = hm.get(key);
            ts.remove(node);
            node.cnt++;
            node.time = ++time;
            ts.add(node);        // 二叉树删除并重新插入来保持有序
            return node.value;
        }
        
        public void put(int key, int value) {
            if(capacity == 0) {
                return;
            }
            if(hm.size() == capacity  && !hm.containsKey(key)) {
                Node temp = ts.pollFirst();
                //System.out.println("===" + temp.key);
                hm.remove(temp.key);
            }
            if(!hm.containsKey(key)) {
                Node node = new Node(key, value, 1, ++time);
                hm.put(key, node);  // node放hashmap
                ts.add(node);       // node放二叉树
                return;
            }
            Node node = hm.get(key);
            ts.remove(node);
            node.value = value;
            node.cnt++;
            node.time = ++time;
            ts.add(node);       // 二叉树删除节点并重新插入来保持有序
        }
    }
