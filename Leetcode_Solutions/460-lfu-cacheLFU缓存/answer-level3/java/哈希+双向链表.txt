LRU是最近最少使用， 使用nodeMap寻址，链表表示访问时间

LFU是最不经常使用，使用nodeMap寻址，freqMap表示每个频次的LRU链表

有很多细节问题，需要调试才能找到

```
class LFUCache {
    // 容量
    private int capacity;
    // 存放每个key对应的node的位置
    private Map<Integer, LFUNode> nodeMap = new HashMap<>();
    // 存放每个访问频次对应的链表 key为访问频次 （按LRU方式，最新访问的在链表头，删除时删链表尾）
    private Map<Integer, LFUNode[]> freqMap = new HashMap<>();
    // 记录最小访问频次，方便移除元素
    private int minFreq;

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (nodeMap.get(key) == null) {
            return -1;
        }
        LFUNode node = nodeMap.get(key);
        // 将node从链表中删掉，然后再放到+1频次的链表中
        adjust(node);
        // 返回值
        return node.value;
    }
    
    public void put(int key, int value) {
        // 容量为0，不允许添加
        if (capacity == 0) {
            return;
        }
        int size = nodeMap.size();
        // 先看map中是否有
        LFUNode node = nodeMap.get(key);
        boolean inLink = true;
        if (node == null) {
            node = new LFUNode(key, value);
            nodeMap.put(key, node);
            inLink = false;
        }
        // 如果之前在链表中，调整一下就可以了
        if (inLink) {
            node.value = value;
            adjust(node);
        } else {
            // 不在链中，需要判断当前数量是否超过容量，移除访问频次最小的链表的尾元素
            // 调试出来判断逻辑不对（当不存key时，应该用之前的容量判断）
            if (size >= capacity) {
                LFUNode[] headTail = freqMap.get(this.minFreq);
                remove(headTail[1].pre, true);
            }
            addNode(node);
            // 调整minFreq
            if (minFreq != 1) {
                minFreq = 1;
            }
        }
    }

    // 调整节点， 从原链表加到新链表
    private void adjust(LFUNode node) {
        // 从原频次的链表中移除
        remove(node, false);
        // node的访问频次+1
        node.freq = node.freq + 1;
        // 添加到新频次的链表的表头
        addNode(node);
    }

    // 从node.freq链表中移除node，isDelete表示是否删除该节点
    private void remove(LFUNode node, boolean isDelete) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
        // node所在链表的链表头尾
        LFUNode[] headTail = freqMap.get(node.freq);
        // 空链表从freqMap中移除
        if (headTail[0].next == headTail[1]) {
            freqMap.remove(node.freq, headTail);
            headTail[0] = null;
            headTail[1] = null;
            // 如果当前频次是最小频次，需要重新查找最小频次
            if (this.minFreq == node.freq) {
                this.minFreq = findMinFreq();
            }
        }
        // 如果删除元素，需要将node置空，让java回收内存
        if (isDelete) {
            // 从map中删除
            nodeMap.remove(node.key, node);
            node = null;            
        }        
    }

    // 添加新节点
    private void addNode(LFUNode node) {
        LFUNode[] newHeadTail = freqMap.get(node.freq);
        if (newHeadTail == null) {
            // 当前频次还没有链表，需要新建
            newHeadTail = new LFUNode[2];
            newHeadTail[0] = new LFUNode(0, 0);
            newHeadTail[1] = new LFUNode(0, 0);
            newHeadTail[0].next = newHeadTail[1];
            newHeadTail[1].pre = newHeadTail[0];            
            freqMap.put(node.freq, newHeadTail);
            // 更新最小频次 调试出来的问题
            minFreq = Math.min(minFreq, node.freq);
        }        
        node.next = newHeadTail[0].next;
        node.pre = newHeadTail[0];
        node.next.pre = node;
        newHeadTail[0].next = node;
    }

    // 查找最小频次
    private int findMinFreq() {
        int min = Integer.MAX_VALUE;
        for (int freq : freqMap.keySet()) {
            min = Math.min(min, freq);
        }
        return min;
    }

    class LFUNode {
        int key;
        int value;
        int freq = 1;
        LFUNode pre;
        LFUNode next;
        LFUNode(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }


    public static void main(String[] args) {
        LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );

        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println(cache.get(1));       // 返回 1
        cache.put(3, 3);    // 去除 key 2
        System.out.println(cache.get(2));       // 返回 -1 (未找到key 2)
        System.out.println(cache.get(3));       // 返回 3
        cache.put(4, 4);    // 去除 key 1
        System.out.println(cache.get(1));       // 返回 -1 (未找到 key 1)
        System.out.println(cache.get(3));       // 返回 3
        System.out.println(cache.get(4));       // 返回 4

    }
}
```