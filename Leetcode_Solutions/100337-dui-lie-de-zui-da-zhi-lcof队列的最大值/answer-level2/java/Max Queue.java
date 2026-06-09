### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {

    private List<Integer> contents;
    private List<Integer> maxValues;
    private int queueHead;
    private int queueTail;
    private int maxQueueHead;
    private int maxQueueTail;

    public MaxQueue() {
        contents = new ArrayList<>();
        maxValues = new ArrayList<>();
        queueHead = 0;
        queueTail = 0;
        maxQueueHead = 0;
        maxQueueTail = 0;
    }

    public int max_value() {
        if (maxQueueTail == maxQueueHead) {
            return -1;
        }
        return maxValues.get(maxQueueHead);
    }

    public void push_back(int value) {
        contents.add(queueTail++, value);
        while (maxQueueHead != maxQueueTail && maxValues.get(maxQueueTail - 1) < value) {
            maxQueueTail--;
        }
        maxValues.add(maxQueueTail++, value);
    }

    public int pop_front() {
        if ( queueHead == queueTail) {
            return -1;
        }
        int value = contents.get(queueHead++);
        if (value == maxValues.get(maxQueueHead)) {
            maxQueueHead++;
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