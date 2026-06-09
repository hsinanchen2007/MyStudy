```
public int mySqrt(int x) {

        if (x == 0) {
            return 0;
        }
        long temp = x;
        long left = 1;
        long right = (temp + 1) / 2;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (temp / mid > mid) {
                left = mid + 1;
            } else if (temp / mid < mid) {
                right = mid - 1;
            } else {
                return (int) mid;
            }
        }

        return (int) right;
    }
```
感觉这个除法比乘法好一点，不容易溢出。不过加法还是溢出了，只能转成long
