### 解题思路
* 首先想到的是#878 Nth Magical Number的思路，找到最小公倍数，然后将区间周期化，从而转化为在一个周期内查找满足要求的元素。最初在一个周期内采用上述堆扩展的方式查找，但是会超时。
* 查看解题区的思路，采用二分查找，结合周期，使得查找的区间更小。

### 代码

```java
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        if (n < 1 || a < 1 || b < 1 || c < 1) throw new IllegalArgumentException("invalid param");
        
        // 两两组合的最小公倍数
        long lcmAB = lcm(a, b);
        long lcmAC = lcm(a, c);
        long lcmBC = lcm(b, c);
        // 三个数的最小公倍数
        long lcm = lcm(lcmAB, c);
        
        // lcm之内的数字数目，即一个周期内的元素数
        long m = lcm / a + lcm / b + lcm / c - lcm / lcmAB - lcm / lcmAC - lcm / lcmBC + 1;

        long epoch = n / m;
        long r = n % m;
        long result = epoch * lcm;
		
        if (r > 0) {
            // 二分查找，范围缩小为1～lcm
            long left = 1, right = lcm;
            while (left < right) {
                long mid = left + (right - left) / 2;
                long count = mid / a + mid / b + mid / c - mid / lcmAB - mid / lcmAC - mid / lcmBC + mid / lcm;
                if (count >= r) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            // 最后left就是要查找的值
            result += left;
        }

        return (int)result;
    }
    
    // 最小公倍数
    private long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
    
    // 最大公因数
    private long gcd(long x, long y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
}
```
&emsp;如果$n$是$m$的整数倍，则直接计算即可，时间复杂度为$O(1)$；如果$n$除以$m$还有余数$r$，则需要在$m$的区间内查找第$r$个数，假设最小公倍数为$lcm$，则时间复杂度为$O(\log_2\text{lcm})$。空间复杂度为$O(1)$。理论上比直接使用二分查找性能更好。
执行用时：0ms，在所有java提交中击败了100.00%的用户。

内存消耗：36.5MB，在所有java提交中击败了5.66%的用户。