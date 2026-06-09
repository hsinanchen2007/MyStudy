个人觉得比较好的方法，建立一个2倍大小的数组并存储上下车的时间节点，然后对所有节点进行计算是否越界
```
public boolean carPooling(int[][] trips, int capacity) {
        int len = trips.length;
        int[] location = new int[2 * len];
        for (int i = 0; i < len; i++) {
            location[i] = trips[i][1] * 1000 + 101 + trips[i][0];
            location[len + i] = trips[i][2] * 1000 + trips[i][0];
        }
        Arrays.sort(location);
        int sum = 0, calc;
        for (int i = 0; i < 2 * len; i++) {
            calc = location[i] % 1000;
            if (calc <= 100)
                sum -= calc;
            else
                sum += calc - 101;
            if (sum > capacity)
                return false;
        }
        return true;
```
