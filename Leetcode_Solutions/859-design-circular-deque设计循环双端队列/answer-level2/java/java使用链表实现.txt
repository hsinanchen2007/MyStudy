```
class MyCircularDeque {
    private int capacity = 0;
    private int size = 0;
    private Node tail = new Node(-1);
    private Node first = new Node(-1);

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        capacity = k;
        first.next = tail;
        tail.prev = first;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if(isFull()) {
            return false;
        }
        Node node = new Node(value, first.next, first);
        first.next = node;
        node.next.prev = node;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if(isFull()) {
            return false;
        }
        Node node = new Node(value, tail, tail.prev);
        tail.prev.next = node;
        tail.prev = node;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if(isEmpty()) {
            return false;
        }
        Node front = first.next;
        first.next = front.next;
        first.next.prev = first;
        front.next = null;
        front.prev = null;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if(isEmpty()) {
            return false;
        }
        Node last = tail.prev;
        last.prev.next = tail;
        tail.prev = last.prev;
        last.next = null;
        last.prev = null;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    public int getFront() {
        return first.next.v;
    }
    
    /** Get the last item from the deque. */
    public int getRear() {
        return tail.prev.v;
    }
    
    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return capacity == size;
    }

    class Node {
        int v;
        Node next;
        Node prev;
        public Node(int v) {
            this(v, null);
        }
        public Node(int v, Node next) {
            this(v, next, null);
        }
        public Node(int v, Node next, Node prev) {
            this.v = v;
            this.next = next;
            this.prev = prev;
        }
    }
}

```
## 说明
链表结点使用一个前趋指针和一个后继指针，并维护了首尾：first和tail两个结点，这两个结点不存储值，就是首尾一个标记。