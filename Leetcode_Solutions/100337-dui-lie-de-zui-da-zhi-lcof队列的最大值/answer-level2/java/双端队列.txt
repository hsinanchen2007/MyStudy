### 解题思路
空间换时间
最大值的存储 双端队列max [l,r] 从左到右是递减的
为了保持递减，
在入队value时，需要更新max的右边，将比value小的数都丢弃，才能将value放入右边
在出队value，判断value是不是max的头，最大值已出队，需要更新最大值

### 代码

```java
class MaxQueue {
    LinkedList<Integer> queue = new LinkedList<Integer>();
    LinkedList<Integer> max = new LinkedList<Integer>();
    public MaxQueue() {
    }

    public int max_value() {
        if (max.isEmpty()) return -1;
        else return max.peek();
    }

    public void push_back(int value) {
        // 有新的比前面队列中大的，应该将中间值扔掉，极端情况是清空max，比最大值还大
        while (!max.isEmpty() && value > max.peekLast()) {
            max.pollLast();
        }
        queue.offer(value);
        max.offer(value);
    }

    public int pop_front() {
        if (queue.isEmpty()) return -1;
        int head = queue.poll();
        if (head == max.peek()) {
            max.poll();
        }
        return head;
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
![image.png](https://pic.leetcode-cn.com/4e698e2f13ed2a54cacd1f6850fbb7a5ba40bf8c4fe038ae0b1d67dbf01d6167-image.png)
