### 解题思路

### 方法1 直接利用了 Math.sqrt 相关方法，投机取巧的实现

```java
class Solution {
    public int mySqrt(int x) {
        return (int)Math.floor(Math.sqrt(x));
    }
}
```

### 方法2 二分查找

二分查找算法：
- https://blog.csdn.net/v_july_v/article/details/7093204
- https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/er-fen-cha-zhao-xiang-jie

```java
class Solution {
   public int mySqrt(int x) {
        long left = 0;
        long right = x / 2;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            // 该值为 mid ^ 2，如果 mid 使用 int，在 x=2147395599 时, 则 mid * mid 会先越界，再被转型成 long
            long sqr = mid * mid;
            // 该值为（mid + 1）^ 2
            long nextSqr = (mid + 1) * (mid + 1);

            if (sqr <= x && nextSqr > x) {
                // mid*mid <= x < (mid+1)^2 时，解就是 mid
                return (int) mid;
            } else if (sqr > x) {
                right = mid - 1;
            } else if (sqr < x) {
                left = mid + 1;
            }
        }
        // 这个地方 return x 处理的妙，适配了 0 和 1 这两个特殊情况
        return x;
    }
}
```