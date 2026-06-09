一般题解应该是使用循环队列，我这里取个巧直接使用数组，时间83%，内存100%

```
class MovingAverage {

    int size;
    int[] data;
    int cur = 0;
    int tail = 0;
    public MovingAverage(int size) {
        this.size = size;
        data = new int[size];
    }

    public double next(int val) {
        data[tail] = val;
        tail = (tail + 1) % size;
        if (cur < size) {
            cur ++;
        }
        double sum = 0;
        for (int i = 0; i < cur; i++) {
            sum += data[i];
        }
        return sum / cur;
    }
}
```
