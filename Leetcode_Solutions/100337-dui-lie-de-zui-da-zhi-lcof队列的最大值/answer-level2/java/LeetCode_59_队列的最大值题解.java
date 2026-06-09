### 解题思路

- 双端队列和流处理

### 代码

```java
package com.company.simple;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * @description: 队列中的最大值, 使用单调队列和队列来做
 * @author: 15262
 * @date: 2020/3/7
 */

class MaxQueueNew {

    private Deque<Integer> queue;

    private Deque<Integer> sort;

    public MaxQueueNew() {
        queue = new ArrayDeque<>();
        sort = new ArrayDeque<>();
    }

    public int max_value() {

        return queue.isEmpty() ? -1 : sort.peek();

    }

    public void push_back(int value) {

        queue.offer(value);

        // 经过这次循环之后，sort中的都是数组中
        while (!sort.isEmpty() && value > sort.peekLast()) {
            sort.pollLast();
        }

        sort.offer(value);

    }

    public int pop_front() {

        if (queue.size() > 0) {
            Integer val = queue.poll();

            if (val.equals(sort.peek())) {
                sort.pop();
            }

            return val;
        }
        return -1;

    }
}

class MaxQueue {

    private Queue<Integer> queue;

    public MaxQueue() {
        queue = new LinkedList<>();
    }

    public int max_value() {
        return queue.stream().max(Integer::compareTo).orElse(-1);
    }

    public void push_back(int value) {
        queue.offer(value);
    }

    public int pop_front() {
        Integer val = queue.poll();
        if (val == null) {
            return -1;
        }
        return val;
    }
}

public class LeetCode_59_LCOF {

    public static void main(String[] args) {
        MaxQueueNew obj = new MaxQueueNew();
        obj.push_back(2);
        obj.push_back(3);
        obj.push_back(4);
        int param_1 = obj.max_value();
        System.out.println(param_1);
        int param_2 = obj.pop_front();
        System.out.println(param_2);
        int param_3 = obj.max_value();
        System.out.println(param_3);
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