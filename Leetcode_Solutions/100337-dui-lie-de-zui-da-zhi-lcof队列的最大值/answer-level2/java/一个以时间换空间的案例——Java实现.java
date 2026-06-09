### 解题思路
执行结果：用时88ms，击败5.58%用户，内存消耗49.4MB，击败100.00%用户

思路很简单，自己实现一个双向队列，但是和普通双向队列的区别在于每个节点上又新增了两个用于追溯节点顺序的指针。

以普通双向队列的方式实现入队和出队都直接在头指针和尾指针处操作，出队时间复杂度为O(1)，入队时间复杂度为O(1)+插入排序时间复杂度O(n)
通过在入队操作时对插入的节点使用新的“排序指针”来进行一次插入排序（降序），后续获取最大值时直接取排序列表的第一个节点即可，时间复杂度为O(1)

这里可以优化的点是对列表排序是采用其它排序算法以加快插入速度，最大可优化到O(logn)，因此理论上这种方式实现的MaxQueue的时间复杂度和空间复杂度都是最优的。

### 代码

```java
class MaxQueue {

    class Node {
        int val;
        //双向队列，实现队列入出队O(1)操作
        Node prev;
        Node next;
        //排序双向队列，实现获取队列最大值O(1)操作
        Node cext;
        Node crev;

        public int getVal() {
            return val;
        }

        public void setVal(int val) {
            this.val = val;
        }

        public Node getPrev() {
            return prev;
        }

        public void setPrev(Node prev) {
            this.prev = prev;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }

        public Node getCext() {
            return cext;
        }

        public void setCext(Node cext) {
            this.cext = cext;
        }

        public Node getCrev() {
            return crev;
        }

        public void setCrev(Node crev) {
            this.crev = crev;
        }
    }

        private Node head, tail, maxHead;
        public MaxQueue() {
            this.head = this.tail = new Node();
            this.maxHead = new Node();
        }

        public int max_value() {
            if (maxHead.getCext() == null) {
                return -1;
            }
            
            return maxHead.getCext().getVal();
        }

        public void push_back(int value) {
            Node node = new Node();
            node.setVal(value);
            node.setPrev(tail);
            tail.setNext(node);
            tail = node;

            //整理排序队列
            if (maxHead.getCext() == null) {
                maxHead.setCext(node);
                node.setCrev(maxHead);
            } else {
                Node tmp = maxHead.getCext();
                while (tmp.getCext() != null && value < tmp.getVal()) {
                    tmp = tmp.getCext();
                }
                if (value > tmp.getVal()) {
                    tmp.getCrev().setCext(node);
                    node.setCrev(tmp.getCrev());
                    node.setCext(tmp);
                    tmp.setCrev(node);
                } else {
                    node.setCrev(tmp);
                    node.setCext(tmp.getCext());
                    if (tmp.getCext() != null) {
                        tmp.getCext().setCrev(node);
                    }
                    tmp.setCext(node);
                }
            }
        }

        public int pop_front() {
            if (head.getNext() == null) {
                return -1;
            }

            Node node = head.getNext();
            if (tail == node) {
                tail = head;
            }
            node.getPrev().setNext(node.getNext());
            if (node.getNext() != null) {
                node.getNext().setPrev(node.getPrev());
            }
            node.setPrev(null);
            node.setNext(null);

            //整理排序队列
            if (node.getCext() != null) {
                node.getCext().setCrev(node.getCrev());
            }
            node.getCrev().setCext(node.getCext());
            node.setCrev(null);
            node.setCext(null);

            return node.getVal();
        }
    }

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```