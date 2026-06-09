```
class MyCircularDeque {

    /**
     * Initialize your data structure here. Set the size of the deque to be k.
     */


    public MyCircularDeque(int k) {
      this.size = k;
      head = new Node(-1);
      tail = new Node(-1);
      head.next = tail;
      tail.prev = head;
    }


    /**
     * Adds an item at the front of Deque. Return true if the operation is successful.
     */
    public boolean insertFront(int value) {
      if (isFull()) {
        return false;
      }
      new Node(value, head, head.next);
      count++;
      return true;
    }

    /**
     * Adds an item at the rear of Deque. Return true if the operation is successful.
     */
    public boolean insertLast(int value) {
      if (isFull()) {
        return false;
      }
      new Node(value, tail.prev, tail);
      count++;
      return true;
    }

    /**
     * Deletes an item from the front of Deque. Return true if the operation is successful.
     */
    public boolean deleteFront() {
      if (isEmpty()) {
        return false;
      }

      Node node = head.next;

      head.next = head.next.next;
      head.next.prev = head;

      node.prev = null;
      node.next = null;
      count--;
      return true;
    }

    /**
     * Deletes an item from the rear of Deque. Return true if the operation is successful.
     */
    public boolean deleteLast() {
      if (isEmpty()) {
        return false;
      }

      Node node = tail.prev;

      tail.prev = tail.prev.prev;
      tail.prev.next = tail;

      node.prev = null;
      node.next = null;//gc
      count--;
      return true;
    }

    /**
     * Get the front item from the deque.
     */
    public int getFront() {
      if (isEmpty()) {
        return -1;
      }
      return head.next.val;
    }

    /**
     * Get the last item from the deque.
     */
    public int getRear() {
      if (isEmpty()) {
        return -1;
      }
      return tail.prev.val;
    }

    /**
     * Checks whether the circular deque is empty or not.
     */
    public boolean isEmpty() {
      return count == 0;
    }

    /**
     * Checks whether the circular deque is full or not.
     */
    public boolean isFull() {
      return count == size;
    }

    private int size;
    private int count = 0;
    private Node head;
    private Node tail;

    private class Node {

      Node prev;
      Node next;
      int val;

      public Node(int val) {
        this.val = val;
      }

      public Node(int val, Node prev, Node next) {
        this(val);
        this.prev = prev;
        this.next = next;
        prev.next = this;
        next.prev = this;
      }

      @Override
      public String toString() {
        return val + "";
      }
    }

  }
```
