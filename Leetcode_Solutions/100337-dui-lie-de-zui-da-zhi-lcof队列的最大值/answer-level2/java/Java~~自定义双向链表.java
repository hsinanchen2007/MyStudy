定义一个双向链表，用双向链表分别定义排序队列和最大值队列

```
class Node {
    Node prev;
    Node next;
    Integer value;

    public Node(Node prev, Node next, Integer value){
        this.prev = prev;
        this.next = next;
        this.value = value;
    }
}
```

```
class Dequeue {
    Node head;
    Node tail;

    public Dequeue(){
        head = new Node(null, null, null);
        tail = new Node(null, null, null);
        head.next = tail;
        tail.prev = head;
    }

    public void  pushBack(Integer value){
        Node newNode = new Node(null, null, value);
        Node prev = tail.prev;
        prev.next = newNode;
        newNode.prev = prev;
        newNode.next= tail;
        tail.prev = newNode;
    }

    public void pushFront(Integer value){
        Node newNode = new Node(null, null, value);
        Node next = head.next;
        head.next = newNode;
        newNode.prev = head;
        newNode.next = next;
        next.prev = newNode;
    }

    public Integer back(){
        if(isEmpty()){
            return null;
        }

        return tail.prev.value;
    }

    public Integer front(){
        if(isEmpty()){
            return null;
        }

        return head.next.value;
    }

    public Integer popBack(){
        if(isEmpty()){
            return null;
        }

        int pop = tail.prev.value;
        Node newPrev = tail.prev.prev;
        tail.prev = newPrev;
        newPrev.next = tail;
        return pop;
    }

    public Integer popFront(){
        if(isEmpty()){
            return null;
        }

        int pop = head.next.value;
        Node newNext = head.next.next;
        head.next = newNext;
        newNext.prev = head;

        return pop;
    }

    public boolean isEmpty(){
        return head.next == tail;
    }

    public void print(){
        Node node = head.next;
        while(node!=tail){
            System.out.println(node.value);
            node = node.next;
        }
    }
}
```

```
class MaxQueue {
    Dequeue order;
    Dequeue max;

    public MaxQueue() {
        order = new Dequeue();
        max = new Dequeue();
    }
    
    public int max_value() {
        if(max.isEmpty()){
            return -1;
        }

        return max.front();
    }
    
    public void push_back(int value) {
        order.pushBack(value);

        while(!max.isEmpty()&&max.back()<value){
            max.popBack();
        }

        max.pushBack(value);
    }
    
    public int pop_front() {
        if(order.isEmpty()){
            return -1;
        }

        int pop = order.popFront();

        if(pop == max.front()){
            max.popFront();
        }

        return pop;
    }
}
```