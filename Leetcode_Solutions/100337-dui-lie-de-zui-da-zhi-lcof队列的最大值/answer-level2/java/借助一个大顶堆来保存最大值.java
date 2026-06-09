### 解题思路
一个队列来实现逻辑，一个大顶堆来记录最大值

### 代码

```java
class MaxQueue {

    Queue<Integer> queue;
    PriorityQueue<Integer> priorityQueue;
    int max = -1;

    public MaxQueue() {
        queue = new LinkedList<>();
        priorityQueue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
    }

    public int max_value() {
        if (priorityQueue.isEmpty()) {
            return -1;
        }
        return priorityQueue.peek();
    }

    public void push_back(int value) {
        queue.add(value);
        priorityQueue.add(value);
    }

    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        }
        int value = queue.poll();
        if (!priorityQueue.isEmpty()) {
            priorityQueue.remove(value);
        }
        return value;
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