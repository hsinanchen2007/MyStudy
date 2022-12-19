> 不使用伪头和伪尾节点，在做删除插入头和尾节点时需额外判断，建议使用伪头和伪尾节点

```
class MyLinkedList {  
    /**
     * 头节点
     */
    private Node head;
    private Node tail;
    /**
     * 链表的长度
     */
    private int length;

    /** Initialize your data structure here. */
    public MyLinkedList() {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     * */
    public int get(int index) {
        return checkIndex(index) ? -1 : node(index).e;
    }
    
    private boolean checkIndex(int index) {
        return index < 0 || index >= length;
    }
    
    Node node(int index) {
        if (index < length >> 1) {
            Node current = head;
            //使用头指针获取
            for (int i = 0; i < index; i++) {
                current = current.next;
            }
            return current;
        } else {
            //使用尾指针获取
            Node current = tail;
            for (int i = length - 1; i > index; i--) {
                current = current.pre;
            }
            return current;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
     * */
    public void addAtHead(int val) {
        if (isFirstAdd(val)) return;
        //添加当前节点的前驱节点和后继节点，更新当前节点为头节点
        head = new Node(null, val, head);
        //将原来头节点即现在头节点的下一个节点的前驱节点指向新头节点
        head.next.pre = head;
        length++;
    }
    
    private boolean isFirstAdd(int val) {
        if (head == null) {
            head = tail = new Node(val);
            length++;
            return true;
        }
        return false;
    }

    /** Append a node of value val to the last element of the linked list.
     * */
    public void addAtTail(int val) {
        if (isFirstAdd(val)) return;
        //添加当前节点的前驱和后继节点，更新当前节点为尾节点
        tail = new Node(tail, val, null);
        //将原来尾节点即现在尾节点的前驱节点，将其的后继节点指向新尾节点
        tail.pre.next = tail;
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list.If index is greater than the length, the node will not be inserted.
     * */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }
        //原index位置的节点
        Node old = node(index);
        //将old节点作为新节点的后继节点，将old节点的前驱节点作为新节点的前驱节点
        Node current = new Node(old.pre, val, old);
        //将old节点的前驱节点的下一个节点更新为当前节点
        old.pre.next = current;
        //将old节点的前驱节点更新为当前节点
        old.pre = current;
        length++;
    }

    /** Delete the index-th node in the linked list, if the index is valid.
     * */
    public void deleteAtIndex(int index) {
        if (checkIndex(index)) return;
        //获取到删除元素
        Node current = node(index);
        //删除头节点，需要更新head
        if (index == 0) {
            head = current.next;
        } else {
            //将current 的前驱节点的后继节点指向current的后继节点
            current.pre.next = current.next;
        }
        //删除尾节点，需要更新tail
        if (index == length - 1) {
            tail = current.pre;
        } else {
            //将current的后继节点的前驱节点指向current 的前驱节点
            current.next.pre = current.pre;
        }
        length--;
    }
    
      static class Node {
        /**
         * 指向前驱节点，后继节点
         */
        Node pre, next;
        /**
         * 数据域
         */
        int e;

        public Node(int e) {
            this.e = e;
        }

        public Node(Node pre, int e, Node next) {
            this.pre = pre;
            this.e = e;
            this.next = next;
        }
    }

}
```
