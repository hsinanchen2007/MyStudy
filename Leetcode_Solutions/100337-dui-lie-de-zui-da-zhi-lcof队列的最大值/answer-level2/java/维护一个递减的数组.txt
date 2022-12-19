### 解题思路
假设我们当前要入队列的数据为 1，9，6，10，8，5，9
我们发现，1，9，6的出队都不会影响最大值，因此我们维护一个最大值的数组时，1，9，6就没必要存储，只需要存储10就行，对于8，5，9，我们发现，8，5没必要存储，只需要存储9就行。
所以整体的思路就是，每次一个新元素入队时，我们就依据最大值数组，从后往前比较，直到我们找到一个不比当前值小的元素，使整个最大值数组整体递减（存在相邻元素相等），当然时间复杂度不是O（1）。。
代码中的left和right，分别指max数组的左右下标。

### 代码

```java
class MaxQueue {

    private Queue<Integer> queue;
    private int[] max;
    private int left;
    private int right;

    public MaxQueue() {
        queue = new LinkedList<>();
        max = new int[10000];
        left = 0;
        right = 0;
    }

    public int max_value() {
        if (queue.isEmpty())
            return -1;
        return max[left];
    }

    public void push_back(int value) {
        queue.add(value);
        int k = right;
        while (k >= left && max[k] < value){
            max[k] = 0;
            k--;
        }
        if (k == left - 1){
            max[left] = value;
            right = left;
        }
        else {
            k++;
            max[k] = value;
            right = k;
        }
    }

    public int pop_front() {
        if (queue.isEmpty())
            return -1;
        Integer poll = queue.poll();
        if (poll == max[left]){
            max[left] = 0;
            left++;
        }
        return poll;
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