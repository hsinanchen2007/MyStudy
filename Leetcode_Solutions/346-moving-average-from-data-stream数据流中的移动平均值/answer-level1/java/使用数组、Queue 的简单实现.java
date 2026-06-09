## 解法一：使用数组
### 解题思路
该题并没有要求能够 deQueue，所以窗口大小（size）只增不减。利用这点，在计算平均值时只需遍历整个数组，再除以 size 即可。

### 代码
```java
class MovingAverage {
    int[] nums;
    int capacity;
    int head;
    int size = 0;

    public MovingAverage(int size) {
        capacity = size;
        nums = new int[size];
        head = -1;
    }

    public double next(int val) {
        head = (head + 1) % capacity;
        nums[head] = val;
        size = (size == capacity) ? capacity : size + 1;
        return getAverage();
    }

    private double getAverage() {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        return sum / (double) size;
    }
}
```

## 解法二：使用 Queue
### 解题思路
该题并没有限制使用的数据类型，故利用 Queue 的特性即可轻松解决。

### 代码
``` Java
class MovingAverage {
    int capacity;
    Queue<Integer> q = new LinkedList<>();

    public MovingAverage(int size) {
        capacity = size;
    }
    
    public double next(int val) {
        if (q.size() == capacity) {
            q.poll();
        }
        q.offer(val);
        return getAverage();
    }

    private double getAverage() {
        int sum = 0;
        for (Integer x : q) {
            sum += x;
        }
        return sum / (double) q.size();
    }
}
```