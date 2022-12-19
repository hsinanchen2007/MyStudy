### 解题思路
用第一个队列保存加入的顺序
用另外一个队列进行排序保存
共同入，共同出

### 代码

```java
class MaxQueue {

    private Queue<Integer> queue;
    private Queue<Integer> list;

    public MaxQueue() {
        queue = new PriorityQueue<>((a, b) -> {
            if (a > b) {
                return -1;
            } else if (a == b) {
                return 0;
            } else {
                return 1;
            }
        });

        list = new LinkedList<>();
    }

    public int max_value() {
        Integer m = this.queue.peek();
        if (m != null) {
            return m.intValue();
        } else {
            return -1;
        }
    }

    public void push_back(int value) {
        this.queue.offer(value);
        this.list.offer(value);
    }

    public int pop_front() {
        Integer t = this.list.poll();
        if (t != null) {
            this.queue.remove(t);
            return t;
        }else{
            return -1;
        }
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