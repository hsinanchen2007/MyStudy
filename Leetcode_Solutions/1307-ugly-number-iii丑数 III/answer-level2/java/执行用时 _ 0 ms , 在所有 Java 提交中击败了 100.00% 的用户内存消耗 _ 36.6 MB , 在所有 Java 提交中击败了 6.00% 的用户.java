### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public int nthUglyNumber(int n, int a, int b, int c) {
        long l = 1;
        long r = 2000000000;
        long ab = a / gcd(a, b) * b;
        long ac = a / gcd(a, c) * c;
        long bc = b / gcd(b, c) * c;
        long abc = ab / gcd(ab, c) * c;
        while(l < r) {
            long mid = (l + r) / 2;
            long sum = mid / a + mid / b + mid / c;
            sum -= mid / ab + mid / bc + mid / ac;
            sum += mid / abc;
            if(sum < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return (int)l;
    }
     private long gcd(long p, long q) {
        if(p == 0) {
            return q;
        }
        return gcd(q % p, p);
    }
}
```