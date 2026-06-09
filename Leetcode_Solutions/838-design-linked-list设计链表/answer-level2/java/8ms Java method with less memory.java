```
class MyLinkedList {
    
    public class Node {
        int val;
        Node next;
        
        public Node(int val) {
            this.val = val;
        }
    }

    public Node head;
    
    /** Initialize your data structure here. */
    public MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index < 0)
            return -1;
        int i = 0;
        Node curr = head;
        while (i < index) {
            curr = curr.next;
            if (curr == null)
                return -1;
            i++;
        }
        return curr.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node node = new Node(val);
        node.next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node node = new Node(val);
        if (head == null) {
            node.next = head;
            head = node;
        } else {
            Node curr = head;
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node node = new Node(val);
        int i = 0;
        Node curr = head;
        Node prev = null;
        while (i < index) {
            prev = curr;
            if (prev == null)
                break;
            curr = curr.next;
            i++;
        }
        if (prev != null) {
            prev.next = node;
            node.next = curr;            
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        int i = 0;
        Node curr = head;
        Node prev = null;
        if (index == 0) {
            head = head.next;
            return;
        }
        while (i < index) {
            prev = curr;
            curr = curr.next;
            if (curr == null) 
                break;
            i++;
        }
        if (curr != null) {
            Node next = curr.next;
            prev.next = next;       
        }
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
