### 解题思路
维护一个头尾节点

### 代码

```java
class MyLinkedList {

   
    private Node head;
    private Node tail;
    private int size;

    class Node{
        int val;
        Node next;
        Node(int val){
            this.val = val;
            this.next = null;
        }
    }
    /** Initialize your data structure here. */
    public MyLinkedList() {
        size = 0;
        head = new Node(-1);
        tail = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        //索引无效
        if (index < 0 || index >= size || size == 0)
            return -1;
        Node temp = head.next;
        while (index != 0 && temp!= null){
            index--;
            temp = temp.next;
        }
        return temp.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node temp = new Node(val);
        temp.next = head.next;
        head.next = temp;
        //保证尾节点有序
        if (tail == head)
            tail = head.next;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node temp = new Node(val);
        tail.next = temp;
        tail = temp;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0)
            addAtHead(val);
        else if (index > size)
            ;
        else if (index == size)
            addAtTail(val);
        else {
            // 0 - size-1
            size++;
            Node temp = head.next;
            Node pre = head;
            while (index != 0){
                index--;
                pre = temp;
                temp = temp.next;
            }
            Node tmp = new Node(val);
            tmp.next = temp;
            pre.next = tmp;
            if (temp.next == null){
                tail = temp;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            ;
        //索引有效
        else {
            // 0 - size-1
            size--;
            Node temp = head.next;
            Node pre = head;
            while (index != 0){
                index--;
                pre = temp;
                temp = temp.next;
            }
            pre.next = temp.next;
            if (temp.next == null)
                tail = pre;
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