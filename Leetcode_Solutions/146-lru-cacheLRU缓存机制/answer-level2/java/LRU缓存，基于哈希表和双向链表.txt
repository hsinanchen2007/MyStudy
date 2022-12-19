### 解题思路
1. 参考大神的思路，走了一遍，不是自己写的，详细解释见代码。

### 代码

```java
class Node{ //建顶点类
    public int key, value;
    public Node prev, next;
    public Node(int k, int v){
        key = k;
        value = v;
    }
}

class DoubleList{ //双向链表类
    private Node head, tail;
    private int size;

    public DoubleList(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
        size = 0;
    }

    public void insertHead(Node node){
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
        size++;
    }

    public void deleteNode(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        size--;
    }

    public Node deleteTail(){
        if(tail.prev == head) return null;
        Node t = tail.prev;
        deleteNode(t);
        return t;
    }

    public int getSize(){
        return size;
    }
}


class LRUCache {
    private DoubleList doublelist;
    private Map<Integer, Node> map;
    private int capacity;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        doublelist = new DoubleList();
    }
    
    public int get(int key) {
        if(!map.containsKey(key)) return -1;
        int v = map.get(key).value; //得到指定值
        put(key, v); //更新这个顶点的信息
        return v;
    }
 
    public void put(int key, int value) {
        Node n = new Node(key, value); //创建新的顶点
        if(map.containsKey(key)){ //如果map中存在的话，将链表中的原顶点删除，再插入新顶点，并更新map中的值
            doublelist.deleteNode(map.get(key));
            doublelist.insertHead(n);
            map.put(key, n);
        }
        else{
            if(map.size() == capacity){//如果map满了，map和链表均删除最久不用的顶点
                Node d = doublelist.deleteTail();
                map.remove(d.key);
            }
            doublelist.insertHead(n);//无论满没满，都要插入新的顶点。
            map.put(key, n);//无论满没满，都要插入新的顶点。
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```