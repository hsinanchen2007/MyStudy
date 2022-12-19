![image.png](https://pic.leetcode-cn.com/99c1070db3222674547037f6743098202b2ae9b3cc20606f2d533f7f3f98ef17-image.png)

### 解题思路
为方便区分，将数值队列命名为numsQueue，额外维护一个最大值队列（maxQueue），该队列满足性质：
1. （1）队首元素即为当前队列（numsQueue）中所有元素的最大值
2. 插入新元素val时，数值队列按正常方式插入元素；对maxQueue的插入方式如下：
- 如果val小于或等于maxQueue队列的队尾元素，则直接追加到该队列队尾。
- 如果val大于队尾元素，则将队列中比val小的元素去除，此时需遍历一遍队列，找到第一个小于val的元素；然后将val插入队列
3. 删除元素时，如果数值队列numsQueue队首元素等于max，则删除maxQueue队首元素，max指向下一个队首元素。



### 代码

```java
class MaxQueue {
    Node front1, rear1, front2, rear2;
    int max;
    int last;

    static class Node {
        int val;
        Node next;

        public Node(int val) {
            this.val = val;
        }
    }

    public MaxQueue() {
        front1 = new Node(0);
        rear1 = front1;
        max = Integer.MIN_VALUE;
        last = max;
        front2 = new Node(max);
        rear2 = front2;
    }

    public int max_value() {
        if (front1 == rear1) return -1;
        return max;
    }

    public void push_back(int value) {
        rear1.next = new Node(value);
        rear1 = rear1.next;
        Node newNode = new Node(value);
        if (value <= last) {
            rear2.next = newNode;
            rear2 = rear2.next;
        } else {
            Node curr = front2.next, pre = front2;
            while (curr != null && curr.val > value) {
                pre = curr;
                curr = curr.next;
            }
            pre.next = newNode;
            rear2 = newNode;
        }
        last = value;
        max = Math.max(max, value);
    }

    public int pop_front() {
        if (front1 == rear1) return -1;
        front1 = front1.next;
        int val = front1.val;
        if (val == max) {
            front2.next = front2.next.next;
            if (front2.next == null) {
                max = front2.val;
                last = max;
            } else {
                max = front2.next.val;
            }
        }
        return val;
    }
}
```