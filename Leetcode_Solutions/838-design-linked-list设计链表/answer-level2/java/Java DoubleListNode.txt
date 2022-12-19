```java
class MyLinkedList {
    class DoubleListNode {
        int val;
        DoubleListNode next, prev;
        DoubleListNode(int x) { val = x; }
    }
    int size = 0;
    DoubleListNode dummyHead = null;
    DoubleListNode dummyTail = null;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        dummyHead = new DoubleListNode(-1);
        dummyTail = new DoubleListNode(-1);
        dummyTail.prev = dummyHead;
        dummyHead.next = dummyTail;
        size  = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index < 0 || index >= size) return -1;
        DoubleListNode node = dummyHead.next;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        return node.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        DoubleListNode cur = new DoubleListNode(val);
        
        cur.prev = dummyHead;
        cur.next = dummyHead.next;

        dummyHead.next.prev = cur;
        dummyHead.next = cur;
        
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        DoubleListNode cur = new DoubleListNode(val);
        cur.next = dummyTail;
        cur.prev = dummyTail.prev;
        dummyTail.prev.next = cur;
        dummyTail.prev = cur;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        DoubleListNode cur = new DoubleListNode(val);
        DoubleListNode node = dummyHead;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        cur.next = node.next;
        cur.prev = node;
        node.next.prev = cur;
        node.next = cur;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        DoubleListNode node = dummyHead.next;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        node.prev.next = node.next;
        node.next.prev = node.prev;
        size--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

```
