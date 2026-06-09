正常逻辑思维方法和优化方法

![1574594326035.jpg](https://pic.leetcode-cn.com/5ebe71979ca04c05c7d9dc6c78b4193ce1565f26e930cad577f502cfbaa01a5c-1574594326035.jpg)

优化方法在于不用在循环中，再次循环访问数组。所以我认为时间复杂度是0(m * 3),空间复杂度是0(n);
多申请一个空间是为了不用判断越界问题。参考了[@davidly](/u/davidly/)

```
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] result = new int[n + 1];
        for (int[] book: bookings) {
            int begin = book[0], end = book[1], sum = book[2];
            result[begin - 1] += sum;
            result[end] -= sum;
        }
        int temp = 0;
        for (int i = 0; i < n; i++) {
            result[i] += temp;
            temp = result[i];
        }
        return result;
        // 暴力方法
        // int[] result = new int[n];
        // for (int[] book: bookings) {
        //     int begin = book[0], end = book[1], sum = book[2];
        //     for (int j = begin - 1; j < end; j++) {
        //         result[j] += sum;
        //     }
        // }
        // return result;
    }
```
