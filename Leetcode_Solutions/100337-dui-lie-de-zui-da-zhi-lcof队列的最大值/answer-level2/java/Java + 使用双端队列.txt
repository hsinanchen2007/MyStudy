### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {

        private static final int NO_VAL = -1;
        private Queue<Integer> queue;
        private Deque<Integer> deque;
        

        public MaxQueue() {
            queue = new LinkedList<>();
            deque = new LinkedList<>();
        }

        public int max_value() {
            if (deque.isEmpty())
                return NO_VAL;
            return deque.peekFirst();
        }

        public void push_back(int value) {
            queue.add(value);
            while (!deque.isEmpty() && deque.peekLast() < value)
                deque.pollLast();
            deque.addLast(value);
        }

        public int pop_front() {
            if (queue.isEmpty())
                return NO_VAL;
            
            int ret = queue.poll();
            if (!deque.isEmpty() && deque.peekFirst() == ret)
                deque.pollFirst();
            return ret;
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