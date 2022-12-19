### 解题思路
此处撰写解题思路
比较值得一说的是add和delete
因为需要获取前一个node,设置node的next的值，所以我们可以把while的条件前进一步，index>0改为index>1
获取到前一个node,直接对node进行操作

### 代码

```java
class MyLinkedList {
    private Node head;
    private int capacity;

    public class Node{
        private int val;
        private Node next;

        public Node(int val){
            this.val = val;
            this.next = null;
        }
        public Node(int val, Node node){
            this.val = val;
            this.next = node;
        }
    }

    /** Initialize your data structure here. */
    public MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index >= capacity || index < 0){
            return -1;
        } else {
            Node tmpNode = head;
            while(index > 0){
                tmpNode = tmpNode.next;
                index--;
            }
            return tmpNode.val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node newNode = new Node(val);
        if(head == null){
            head = newNode;
            capacity = 1;
        } else {
            newNode.next = head;
            head = newNode;
            capacity++;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if(head == null){
            addAtHead(val);
        } else{
            Node tmpNode = head;
            while(tmpNode.next != null){
                tmpNode = tmpNode.next;
            }
            Node newNode = new Node(val);
            tmpNode.next = newNode;
            capacity++;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index <= 0){
            addAtHead(val);
            return;
        }
        if(index > capacity) {
            return;
        }
        if(index == capacity ){
            addAtTail(val);
            return;
        }
        Node tmpNode = head;
        while(index > 1){
            tmpNode = tmpNode.next;
            index--;
        }
        tmpNode.next = new Node(val, tmpNode.next);;
        capacity++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(head == null){
            return;
        }
        if(index < 0 || index >= capacity){
            return;
        }
        if(index == 0){ //头结点删除
            head = head.next;
            return;
        }
        Node tmpNode = head;
        while(index > 1){
            tmpNode = tmpNode.next;
            index--;
        }
        tmpNode.next = tmpNode.next.next;

        capacity--;
    }

    public void printAll(){
        if (head == null){
            System.out.println("空链表");
            return;
        }
        Node tmpNode = head;
        while (tmpNode != null){
            System.out.print( tmpNode.val + "->");
            tmpNode = tmpNode.next;
        }
        System.out.print("NULL");
        System.out.println();
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