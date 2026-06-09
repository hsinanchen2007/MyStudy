### 解题思路
很笨的办法，维系一个链表，一个指针middle指向(size/2)个元素，当size为奇数时，直接返回middle，当size为偶数时，返回middle 和下一个节点的平均值。

### 代码

```java
class MedianFinder {

    /** initialize your data structure here. */
    public MedianFinder() {

    }
    
   private Node middle;
    private int size;

    public void addNum(int num) {
        size++;
        //初始化
        Node newNode = new Node(num);
        if (middle == null) {
            middle = newNode;
        } else if (middle.getValue() > num) {
            //添加到左侧
            Node node = middle;
            for (Node previous = node.getPrevious(); previous != null && previous.getValue() > num; previous = previous.getPrevious()) {
                node = previous;
            }
            node.setPrevious(newNode);
            if (size % 2 == 0) {
                middle = middle.getPrevious();
            }
        } else {
            //添加到右侧
            Node node = middle;
            for (Node next = node.getNext(); next != null && next.getValue() <= num; next = next.getNext()) {
                node = next;
            }
            node.setNext(newNode);
            if (size % 2 == 1) {
                middle = middle.getNext();
            }
        }
    }

    public double findMedian() {
        if (size % 2 == 1) {
            return middle.getValue();
        }
        return (middle.getValue() + middle.getNext().getValue()) * 0.5;
    }
}


class Node {
    private int value;
    private Node previous;
    private Node next;


    public Node(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public Node getPrevious() {
        return previous;
    }

    public void setPrevious(Node previous) {
        if (this.previous != null) {
            previous.previous = this.previous;
            this.previous.next = previous;
        }
        this.previous = previous;
        previous.next = this;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        if (this.next != null) {
            next.next = this.next;
            this.next.previous = next;
        }
        this.next = next;
        next.previous = this;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```