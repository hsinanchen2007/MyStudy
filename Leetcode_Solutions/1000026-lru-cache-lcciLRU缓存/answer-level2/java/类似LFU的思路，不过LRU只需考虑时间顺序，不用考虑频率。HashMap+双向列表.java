```
class LRUCache {
// 这题跟LFU类似，但是只淘汰最少使用的，只看时间，不看访问次数
// 那么只用一个hashMap存(key,node)，另一个直接用双向链表即可
    Map<Integer,Node> cache;
    DoublyLinkedList doublyLinkedList;
    int capacity;
    int size;
    public LRUCache(int capacity) {
        this.capacity=capacity;
        cache=new HashMap<>(capacity);
        doublyLinkedList=new DoublyLinkedList();
    }
    // 要点:get操作也算是一次使用，也要讲该节点提前
    public int get(int key) {
        Node node=cache.get(key);
        if(node!=null){
            
            doublyLinkedList.aheadNode(node);
                
            
            return node.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if (capacity==0){
            return;
        }
        Node node=cache.get(key);
        // 此时容量未变，先删除原有双向链表的node
        // 然后修改node.value的值后把它新增双向链表最前
        if(node!=null){
            doublyLinkedList.delNode(node);
            node.value=value;
            doublyLinkedList.addNode(node);
        }else{
            // 如果满了，先找出双向链表最后的一个的key,在cache中删除
            // 然后在双向链表也删除
            if (size==capacity){
                int lastKey=doublyLinkedList.tail.preNode.key;
                cache.remove(lastKey);
                doublyLinkedList.delNode(doublyLinkedList.tail.preNode);
                size--;
            }
            // 最后添加这个node到cache和双向链表中
            Node newNode=new Node(key,value);
            cache.put(key,newNode);
            doublyLinkedList.addNode(newNode);
            size++;
        }

       

    }


    class DoublyLinkedList{
        Node head;
        Node tail;
        public DoublyLinkedList(){
            head=new Node();
            tail=new Node();
            head.nextNode=tail;
            tail.preNode=head;
        }
        // 增加，同样在双向链表最前端增加
        public void addNode(Node node){
            head.nextNode.preNode=node;
            node.nextNode=head.nextNode;
             head.nextNode=node;
             node.preNode=head;
        }
        // 删除，直接删除，或者删除双向链表最后一个也可以
        // 这里选择直接删除，留给上面逻辑判断是否最后一个
        public void delNode(Node node){
            node.nextNode.preNode=node.preNode;
            node.preNode.nextNode=node.nextNode;
        }
        // 将该节点移到最前，get(key)时调用
        public void aheadNode(Node node){
            node.preNode.nextNode=node.nextNode;
            node.nextNode.preNode=node.preNode;
            node.nextNode=head.nextNode;
            head.nextNode.preNode=node;
             node.preNode=head;
             head.nextNode=node;

        }


    }

    class Node{
        int key;
        int value;
        Node preNode;
        Node nextNode;
        public Node(){};
        public Node(int key,int value){
            this.key=key;
            this.value=value;
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
