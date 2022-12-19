### 解题思路
参考甜姨题解 1，使用 Java LinkedHashSet
对 addNode 和 removeNode 进一步封装

### 代码

```java
class LFUCache {
    Map<Integer, Node> cache;
    Map<Integer, LinkedHashSet<Node>> freqMap;
    int capacity;
    int minFreq;  // 最小频次

    public LFUCache(int capacity) {
        cache = new HashMap<>(capacity);
        freqMap = new HashMap<>();
        this.capacity = capacity;
        int minFreq = 1;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) return -1;
        // 更新频率
        updateFreq(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if (capacity == 0) return;
        Node node = cache.get(key);
        if (node == null){
            // 满了，应该移除
            if (cache.size() == capacity){
                removeNode();
            }
            Node newNode = new Node(key, value);
            addNode(newNode);
        } else {
            // 直接覆盖
            node.value = value;
            updateFreq(node);
        }
    }
    /**
     * 更新频率
     */
    public void updateFreq(Node node){
        // 当前缓存的频率
        int freq = node.freq;
        LinkedHashSet<Node> set = freqMap.get(freq);
        // 删除当前频率下的缓存
        set.remove(node);
        // 当前缓存的频率是最小的，并且没有当前频率的缓存了
        if (freq == minFreq && set.size() == 0) minFreq = freq + 1;

        node.freq++;
        LinkedHashSet<Node> newSet = freqMap.get(freq + 1);
        if (newSet == null){
            newSet = new LinkedHashSet<>();
            freqMap.put(freq+1, newSet);
        }
        newSet.add(node);
    }

    /**
     * 移除最小频率的最后一个节点
     */
    public void removeNode(){
        // 移除频率链表中的节点
        LinkedHashSet<Node> set = freqMap.get(minFreq);
        Node node = set.iterator().next();
        set.remove(node);
        // 移除 cache map 中的节点
        Node cacheNode = cache.get(node.key);
        cache.remove(cacheNode.key);
    }

    /**
     * 添加一个新的节点
     */
    public void addNode(Node node){
        int freq = node.freq;
        LinkedHashSet<Node> set = freqMap.get(freq);
        if (set == null){
            set = new LinkedHashSet<>();
            freqMap.put(node.freq, set);
        }
        set.add(node);
        minFreq = node.freq;
        cache.put(node.key, node);
    }


}
class Node{
    int key;
    int value;
    int freq;
    
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
        freq = 1;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```