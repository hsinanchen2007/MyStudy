### 解题思路
疲惫，不写。洗澡去了。

### 代码

```java
public class LFUCache {
    private int capacity;
    private Map<Integer, LFREntry> map;
    private LFUListNode headNode;

    /**
     * 构造方法
     * @param capacity 容量
     */
    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>(capacity);
        this.headNode = null;
    }

    private static class LFUListNode {
        int times;
        LFREntry headEntry;
        LFREntry tailEntry;
        LFUListNode pre;
        LFUListNode next;

        public LFUListNode(int times) {
            this.times = times;
            this.headEntry = null;
            this.tailEntry = null;
        }
    }

    private static class LFREntry {
        int key;
        int value;
        LFUListNode listNode;
        LFREntry pre;
        LFREntry next;

        public LFREntry(int key , int value, LFUListNode listNode) {
            this.key = key;
            this.value = value;
            this.listNode = listNode;
        }
    }


    public int get(int key) {
        // 如果不存在返回-1
        if(!map.containsKey(key)){
            return -1;
        }
        LFREntry entry = map.get(key);
        // 将目标entry从原lru队列上移除
        if(Objects.nonNull(entry.pre)){
            entry.pre.next = entry.next;
        } else {
            entry.listNode.headEntry = entry.next;
        }
        if(Objects.nonNull(entry.next)){
            entry.next.pre = entry.pre;
        } else {
            entry.listNode.tailEntry = entry.pre;
        }
        LFUListNode currentNode = entry.listNode;
        if(Objects.isNull(currentNode.next)){
            currentNode.next = new LFUListNode(currentNode.times + 1);
            currentNode.next.pre = currentNode;
        }
        if(currentNode.next.times != currentNode.times + 1){
            LFUListNode tmp = new LFUListNode(currentNode.times + 1);
            tmp.pre = currentNode;
            tmp.next = currentNode.next;
            currentNode.next = tmp;
            if(Objects.nonNull(tmp.next)){
                tmp.next.pre = tmp;
            }
        }
        // 如果移除元素之后队列为空，则该队列应该移除
        if(Objects.isNull(currentNode.headEntry)){
            if(Objects.nonNull(currentNode.pre)){
                currentNode.pre.next = currentNode.next;
            } else {
                headNode = currentNode.next;
            }
            if(Objects.nonNull(currentNode.next)){
                currentNode.next.pre = currentNode.pre;
            }
        }
        LFUListNode nextNode = currentNode.next;
        // 更新entry中的listNode变量的值
        entry.listNode = nextNode;
        // 放到下一个队列的末尾
        if(Objects.isNull(nextNode.headEntry) && Objects.isNull(nextNode.tailEntry)){
            nextNode.headEntry = entry;
            nextNode.tailEntry = entry;
            entry.pre = null;
            entry.next = null;
        } else {
            nextNode.tailEntry.next = entry;
            entry.pre = nextNode.tailEntry;
            entry.next = null;
            nextNode.tailEntry = entry;
        }
        return entry.value;
    }

    public void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        // 如果map中已经存在该key，则应先淘汰该key
        if(map.containsKey(key)){
            LFREntry entry = map.get(key);
            entry.value = value;
            get(key);
            return;
        }
        // 如果放入元素之后大于预设容量，需要先淘汰元素
        if(map.size() + 1 > capacity){
            LFREntry toBeEliminate = headNode.headEntry;
            LFUListNode currentNode = toBeEliminate.listNode;
            if(Objects.nonNull(toBeEliminate.pre)){
                toBeEliminate.pre.next = toBeEliminate.next;
            } else {
                currentNode.headEntry = toBeEliminate.next;
            }
            if(Objects.nonNull(toBeEliminate.next)){
                toBeEliminate.next.pre = toBeEliminate.pre;
            } else {
                currentNode.tailEntry = toBeEliminate.pre;
            }
            map.remove(toBeEliminate.key);
        }
        // 如果没有头结点的，创建访问次数为0的头结点
        if(Objects.isNull(headNode)) {
            headNode = new LFUListNode(0);
        }
        if(headNode.times != 0) {
            LFUListNode tmp = new LFUListNode(0);
            tmp.next = headNode;
            tmp.next.pre = tmp;
            headNode = tmp;
        }

        // 放入队列的末尾
        LFREntry entry = new LFREntry(key, value, headNode);
        if(Objects.isNull(headNode.tailEntry)){
            headNode.headEntry = entry;
            headNode.tailEntry = entry;
        } else {
            headNode.tailEntry.next = entry;
            entry.pre = headNode.tailEntry;
            headNode.tailEntry = entry;
        }
        // 在map中放入元素
        map.put(key, entry);
    }
}
```