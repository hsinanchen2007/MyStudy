### 解题思路
采用双链表的方式实现,对于尾插法更快,在取节点的时候参考linkList的源码使用 从两头进行查找更快.
### 代码

```java
class MyLinkedList {
 transient int size = 0;
    transient Node first;
    transient Node last;

    public boolean isElementIndex(int index) {
        return index >= 0 && index < size;
    }

    public boolean isPostionIndex(int index) {
        return index >= 0 && index <= size;
    }

    /**
     * Initialize your data structure here.
     */
    public MyLinkedList() {

    }

    private Node  node(int index) {
        if (index > (size >> 1)) {
            Node  temp = last;
            for (int i = size - 1; i > index; i--) {
                temp = temp.prev;
            }
            return temp;
        } else {
            Node  temp = first;
            for (int i = 0; i < index; i++) {
                temp = temp.next;
            }
            return temp;
        }
    }

    /**
     * Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     */
    public int get(int index) {
        if (!isElementIndex(index))
            return -1;
        return (Integer) node(index).item;
    }

    /**
     * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
     */
    public void addAtHead(int val) {
        final Node  f = first;
        final Node  newNode = new Node(null, val, f);
        if (null == f)
            last = newNode;
        else
            f.prev = newNode;
        first = newNode;
        size++;
    }

    /**
     * Append a node of value val to the last element of the linked list.
     */
    public void addAtTail(int val) {
        final Node  l = last;
        final Node  newNode = new Node(l, val, null);
        if (null == l)
            first = newNode;
        else
            l.next = newNode;

        last = newNode;
        size++;
    }

    /**
     * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
     */
    public void addAtIndex(int index, int val) {
        if (!isPostionIndex(index))
            return;
        /* size 可以为0 */
        if (index == size) {
            addAtTail(val);
            return;
        }
        final Node  indexNOde = node(index);
        final Node  preNode = indexNOde.prev;
        final Node  newNode = new Node(preNode, val, indexNOde);
        indexNOde.prev = newNode;
        if (null == preNode)
            first = newNode;
        else
            preNode.next = newNode;
        size++;
    }

    /**
     * Delete the index-th node in the linked list, if the index is valid.
     */
    public void deleteAtIndex(int index) {
        if (!isElementIndex(index))
            return;
        final Node  succ = node(index);
        final Node  prev = succ.prev;
        final Node  next = succ.next;
        succ.next = null;
        succ.prev = null;
        if (null == prev) {
            first = next;
        } else {
            prev.next = next;
        }

        if (null == next)
            last = prev;
        else
            next.prev = prev;
        size--;
    }

    private static class Node  {
        int item;
        Node  next;
        Node  prev;
        public Node(Node  prev, int item, Node  next) {
            this.item = item;
            this.next = next;
            this.prev = prev;
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