### 解题思路

修改了题解中双向链表的解法,用TreeMap代替HashMap；
```java
    private int capacity;
    private Map<Integer, LFCNode> cache;
    private TreeMap<Integer, DoubleLinkedList> freqMap;
```
#### put操作时如果到达了capacity边界
    - 获取TreeMap的第一个entrySet,即最少使用的频数entrySet.key,最少使用的节点的集合entrySet.value。
    - 取出entrySet.value中的最近使用的last节点，删除cache.remove(last.key),删除最少最近使用的节点entrySet.value.removeLast()。
    - 如果entrySet.value.isEmpty,则说明当前最少频数的集合都已经增加了，删除该频数的集合freqMap.remove(entrySet.key)
    - 最后存放到freqMap中频数为1的DoubleLinkedList中的first节点
#### get操作时如果存在该节点node
    - 通过该节点node的频数，取出该频数的集合DoubleLinkedList
    - 从DoubleLinkedList中删除该节点，如果DoubleLinkedList为空，则删除该频数的集合freqMap.remove(node.freq)
    - node.freq++后存放到对应频数的集合中的first节点
### 代码

```java
public class LFUCache {

    private int capacity;
    private Map<Integer, LFCNode> cache;
    private TreeMap<Integer, DoubleLinkedList> freqMap;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        cache = new HashMap<>(capacity);
        freqMap = new TreeMap<>();
    }

    public int get(int key) {
        LFCNode node = cache.get(key);
        if(node == null){
            return -1;
        }
        increaseFreq(node);
        return node.value;
    }

    private void increaseFreq(LFCNode node) {
        int freq = node.freq;
        DoubleLinkedList linkedList = freqMap.get(freq);
        if(linkedList != null){
            linkedList.remove(node);
            if(linkedList.isEmpty()){
                freqMap.remove(freq);
            }
        }
        node.freq++;
        linkedList = freqMap.get(freq + 1);
        if(linkedList == null){
            linkedList = new DoubleLinkedList();
            freqMap.put(freq+1, linkedList);
        }
        linkedList.add(node);
    }

    public void put(int key, int value) {
        if (capacity == 0){
            return;
        }
        LFCNode node = cache.get(key);
        if(node == null){
            if(cache.size() == capacity){
                Map.Entry<Integer, DoubleLinkedList> next = freqMap.entrySet().iterator().next();
                DoubleLinkedList minLinkedList = next.getValue();
                cache.remove(minLinkedList.last.key);
                minLinkedList.removeLast();
                if(minLinkedList.isEmpty()){
                    freqMap.remove(next.getKey());
                }
            }
            node = new LFCNode(key, value);
            cache.put(key, node);
            DoubleLinkedList linkedList = freqMap.get(1);
            if(linkedList == null){
                linkedList = new DoubleLinkedList();
                freqMap.put(1, linkedList);
            }
            linkedList.add(node);
        }else {
            node.value = value;
            increaseFreq(node);
        }

    }
}

class LFCNode{
    int freq = 1;
    int key;
    int value;
    LFCNode next;
    LFCNode pre;

    public LFCNode(int key, int value){
        this.key = key;
        this.value = value;
    }
}

class DoubleLinkedList{
    LFCNode first;
    LFCNode last;
    public DoubleLinkedList(){
        first = null;
        last = null;
    }

    public boolean isEmpty(){
        return first == null;
    }

    void removeLast(){
        if(first.next == null){
            first = null;
        }else {
            last.pre.next = null;
        }
        last = last.pre;
    }

    void remove(LFCNode node){
        if(node == first){
            first = node.next;
        }else {
            node.pre.next = node.next;
        }
        if(node == last){
            last = node.pre;
        }else {
            node.next.pre = node.pre;
        }
    }

    void add(LFCNode node){
        if(isEmpty()){
            last = node;
        }else {
            first.pre = node;
        }
        node.next = first;
        first = node;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```