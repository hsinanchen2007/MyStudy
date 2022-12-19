该题解无需刻意判断各类边界、越界情况，更易于理解、记忆。

``` Java
class Solution {
    public int mySqrt(int x) {
        long left = 0;
        long right = x / 2;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sqr = mid * mid; // 该值为 mid ^ 2，如果 mid 使用 int，在 x=2147395599 时, 则 mid * mid 会先越界，再被转型成 long
            long nextSqr = (mid + 1) * (mid + 1); // 该值为（mid + 1）^ 2，
 
            if (sqr == x || (sqr < x && nextSqr > x)) {
                return (int) mid;
            } else if (sqr < x) {
                left = mid + 1;
            } else if (sqr > x) {
                right = mid - 1;
            }
        }
        return x;
    }
}
```