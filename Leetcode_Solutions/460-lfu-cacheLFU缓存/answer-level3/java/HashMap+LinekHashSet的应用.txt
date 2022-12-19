### 解题思路
核心思想，用LinkedHashSet的有序性缓存相同频率的时间差异，相同频率时后来的插入到尾部，移动所在频率的列表时候利用O(1)删除特性，移动到新频率列表。
### 代码

```java
class LFUCache {
    Map<Integer, Node> cache = new HashMap<>();
    //缓存 每个不同频率的节点列表，删除时直接删除最低频率的头节点。
    Map<Integer, LinkedHashSet<Node>> freqMap = new HashMap<>();
    int minFreq = 1; //维护最低频率
    int capacity; //容量大小
    int size = 0; //维护大小

    public LFUCache(int capacity) {
        cache = new HashMap<>(capacity);
        freqMap = new HashMap<>();
        this.capacity = capacity;
    }

    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        incFreq(node);
        return node.value;
    }

    private void incFreq(Node node) {
        int freq = node.freq;
        LinkedHashSet<Node> list = freqMap.get(freq);
        list.remove(node);
        if (freq == minFreq && list.size() == 0) {
            minFreq = freq + 1;
        }
        if (list.size() == 0) {
            freqMap.remove(freq);
        }
        node.freq++;
        //放到新频率列表里面，插入到尾部
        LinkedHashSet freqNodes = freqMap.getOrDefault(node.freq, new LinkedHashSet<>());
        freqNodes.add(node);
        freqMap.put(node.freq,freqNodes);
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node node = cache.get(key);
        if (node != null) {
            node.value = value;
            incFreq(node);
        } else {
            if (size == capacity) {
                Node deadNode = getLeastFrequentlyUsedNode();
                cache.remove(deadNode.key);
                size--;
            }
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            LinkedHashSet freqNodes = freqMap.getOrDefault(newNode.freq, new LinkedHashSet<>());
            freqNodes.add(newNode);
            freqMap.put(newNode.freq,freqNodes);
            minFreq=1;
            size++;
        }
    }

    private Node getLeastFrequentlyUsedNode() {
        LinkedHashSet<Node> nodes = freqMap.get(minFreq);
        Node lfuNode = nodes.iterator().next();//找到头节点删除
        nodes.remove(lfuNode);
        //维护一下这个频率缓存的大小
        if (nodes.size() == 0) {
            //删除后，这里不用担心下次下次找最小频率找不到，
            //因为很快就会维护新的最低频率
            freqMap.remove(minFreq);
        }
        return lfuNode;
    }

    private class Node {
        int key;
        int value;
        int freq = 1;//频率，
        public Node() {
        }
        public Node(int key, int value) {
            this.key = key;
            this.value = value;
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