```
/**
*   要求O(1)时间复杂度，很自然想到用Map。
*   所以用双向链表和HashMap解决。
*   插入时直接插入HashMap里，并且同时维护一个双向链表，每次对结点进行操作都要把该节点移到链尾，
*   表满时，要想插入新数据，首先把链表头删除，插入Map时顺便将其链接到到链尾
*   表不满，如果更新数据，将其移动到链尾，如果插入新数据，直接插入Map，连接到表尾，count自加一。
*/
class LRUCache {
    class ListNode{
        int key;
        int val;
        ListNode prev,next;
        public ListNode(int key,int val){
            this.key = key;
            this.val = val;
        }
    }

    private int capacity;
    private int count;
    private ListNode dummy;
    private ListNode tail;
    private Map<Integer,ListNode> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        count = 0;
        map = new HashMap<>();
        dummy = new ListNode(0,0);
        tail = new ListNode(0,0);
        dummy.next = tail;
        tail.prev = dummy;
    }

    public void removeHead(){
        if(dummy.next == tail && tail.prev == dummy){
            return;
        }
        ListNode node = dummy.next;
        dummy.next = node.next;
        node.next.prev = dummy;
        map.remove(node.key);
    }

    public void moveToTail(ListNode node){
        
        removeNode(node);
        appendTail(node);
    }

    public void addNode(ListNode node){
        map.put(node.key,node);
        appendTail(node);
    }

    public void appendTail(ListNode node){
        node.next = tail;
        node.prev = tail.prev;
        node.prev.next = node;
        tail.prev = node;
    }

    public void removeNode(ListNode node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    
    public int get(int key) {
        if(!map.containsKey(key)){
            return -1;
        }
        ListNode node = map.get(key);
        moveToTail(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        ListNode node = new ListNode(key,value);
        if(map.containsKey(key)){
            removeNode(map.get(key));
            addNode(node);
        }else {
            if(count < capacity){
                count++;
                addNode(node);
            }else{
                removeHead();
                addNode(node);
            }
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
