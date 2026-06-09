## 分析
本题的解法类似于数学中的夹逼定理。从两边向中间以二分的方式进行夹击。
里面还有一些小技巧。为了防止数据越界。比如 a很大。我们要比较a*a和b的大小。因为a*a可能超过Integer.MAX_VALUE。所以可以比较a和b/a的大小。
## 代码
```java
public int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int start = 1;
        int end = x / 2 + 1;
        int mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            //防止越界
            if (mid <= x / mid && (mid + 1) > x / (mid + 1)) {
                return mid;
            }
            if (mid > x / mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mid;
    }
```