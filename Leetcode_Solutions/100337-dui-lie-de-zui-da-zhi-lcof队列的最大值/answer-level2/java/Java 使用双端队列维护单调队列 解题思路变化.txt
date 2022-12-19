### 解题思路
最开始的思路， 直接定义一个max属性，始终保存入队的最大值....too young too naive, 因为前面的最大值一旦出列，下一个最大值就获取不到了。。
然后想到再创建一个辅助队列，维护为一个单调递减的（至于入队时怎么排序真没想到，因为压根没想到双端队列呀～）；
想了会最后还是看了题解，使用双端队列来维护该辅助队列就好了，顺便把双端队列的知识又温习了一遍.

看了各位大佬的评论题解，说这题本质上还是滑动窗口问题，还是不太理解，不太懂哪里维护了一个滑动窗口呢？是使用辅助队列的地方吗？
因为入队的时候需要与队尾元素比较，比队尾大，队尾元素出列（相当于滑动窗口的右边界左移动）；
出队的时候，如果与辅助队列的队头元素相同，对头元素出列（相当于滑动窗口的左边界又移）；
大概如此吧
### 代码

```java
class MaxQueue {
private Queue<Integer> queue;
    private Deque<Integer> deque;

    public MaxQueue() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }

    public int max_value() {
        if (queue.isEmpty()) {
            return -1;
        }
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.peek();
    }

    public void push_back(int value) {
        queue.offer(value);
        while (!deque.isEmpty() && deque.peekLast() < value) {
            deque.pollLast();
        }
        deque.offer(value);
    }

    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        }
        int val = queue.poll();
        if (val == deque.peek()) {
            deque.pollFirst();
            return val;
        }
        return val;
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