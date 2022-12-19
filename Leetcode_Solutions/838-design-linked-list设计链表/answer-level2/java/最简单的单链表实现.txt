### 解题思路
此处撰写解题思路

### 代码

```java
class MyLinkedList {

    class Node{
        int val;
        Node next;

        public Node(){
            next = null;
            val = 0;
        }
        public Node(int val){
            next = null;
            this.val = val;
        }
        public Node(int val,Node next){
            this.next = next;
            this.val = val;
        }

        @Override
        public String toString() {
            return super.toString();
        }
    }

    int size = 0;
    Node dummHead = null;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        dummHead = new Node();
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        Node curr = dummHead.next;
        for(int i = 0;i< index;i++){
            curr = curr.next;
        }
        return  curr.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        addAtIndex(0,val);
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        addAtIndex(size,val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index > size)
            return;

        Node prev = dummHead;
        for(int i=0;i < index;i++){
            prev = prev.next;
        }
        prev.next = new Node(val,prev.next);
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        Node prev = dummHead;
        for(int i=0;i < index ;i++){
            prev = prev.next;
        }
        prev.next = prev.next.next;
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