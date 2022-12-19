执行结果：
通过
显示详情
执行用时 :
89 ms
, 在所有 Java 提交中击败了
99.15%
的用户
内存消耗 :
50.3 MB
, 在所有 Java 提交中击败了
99.67%
的用户
```
class LRUCache {
    Map<Integer,Node> map;
    int cap;
    int size;
    Node head;
    Node tail;
    
    public LRUCache(int capacity) {
        map = new HashMap<Integer,Node>(capacity);
        cap=capacity;
    }
    
    public int get(int key) {
        Node n = map.get(key);
        if(n!=null){
            del(n);
            addn(n);
            return n.val;
        }else{
            return -1;
        }
    }
    
    public void put(int key, int value) {
        if(map.get(key)==null){
            size++;
        }else{
            Node n = map.get(key);
            del(n);
            map.remove(key);
        }
        
         if(size>cap){
            map.remove(head.key);
            if(head.next!=null)head.next.pre=null;
            head = head.next;
            size--;
        }
        Node n = new Node(key,value);
        map.put(key,n);
        addn(n);
    }
    
     private void del(Node n){
        if(head==n){
            if(head.next!=null){
                head.next.pre=null;
            }else{
                tail=null;
            }
            head = head.next;

        }else if(tail==n){
            if(tail.pre!=null)tail.pre.next=null;
            tail = tail.pre;

        }else{
            n.pre.next = n.next;
            n.next.pre = n.pre;
        }
    }
    
    private void addn(Node n){
        if(tail==null){
            head = n;
        }else{
            tail.next = n;
            n.pre = tail;
        }
        tail=n;
    }
    class Node{
        int key;
        int val;
        Node next;
        Node pre;
        public Node(int key,int val){
            this.key=key;
            this.val=val;
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
