### 解题思路
此处撰写解题思路

### 代码

```java
class LRUCache {
    int capacity;
    DoubleLinkedNode first;
    DoubleLinkedNode last;
    HashMap<Integer, DoubleLinkedNode> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        first = new DoubleLinkedNode(-1,-1);
        last = new DoubleLinkedNode(-1,-1);
        first.next = last;
        last.next = first;
        map = new HashMap();
    }
    
    public int get(int key) {
        if(map.size() == 0 || !map.containsKey(key)) return -1;

        DoubleLinkedNode cur = map.get(key);
        cur.pre.next = cur.next;
        cur.next.pre = cur.pre;
        
        cur.next = first.next;
        cur.pre = first;
        first.next = cur;
        cur.next.pre = cur;
        return cur.value;
    }
    
    public void put(int key, int value) {
        if(!map.containsKey(key) && map.size() < capacity){
            insertNewNode(key, value);
        }else if(!map.containsKey(key)){
            removeLast();
            insertNewNode(key, value);
        }else{
            DoubleLinkedNode getNodeFromMap = map.get(key);
            if(getNodeFromMap.value != value){
                getNodeFromMap.value = value;
            }
            get(key);
        }
    }

    void insertNewNode(int key, int value){
        DoubleLinkedNode newNode = new DoubleLinkedNode(key, value);        
        newNode.next = first.next;
        newNode.next.pre = newNode;
        newNode.pre = first;
        first.next = newNode;
        map.put(key, newNode);
    }

    void removeLast(){
        DoubleLinkedNode lastNode = last.pre;
        lastNode.pre.next = last;
        last.pre = lastNode.pre;
        lastNode.pre = null;
        lastNode.next = null;
        map.remove(lastNode.key);
    }
}

class DoubleLinkedNode{
    DoubleLinkedNode pre;
    DoubleLinkedNode next;
    int key;
    int value;
    DoubleLinkedNode(int key,int val){
        this.key = key;
        this.value = val;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```