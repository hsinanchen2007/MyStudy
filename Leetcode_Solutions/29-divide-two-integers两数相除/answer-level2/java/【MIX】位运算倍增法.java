### 解题思路
位运算倍增求解, 使用异或判断结果正负号

### 代码

```c++ []
typedef long long LL;
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 使用位运算求解
        LL res = 0;
        LL dvd = abs(dividend);
        LL div = abs(divisor);
        while(dvd >= div){
            LL cnt = 1, base = div;
            while(dvd > (base<<1)){
                cnt <<= 1;
                base <<= 1;
            }
            res += cnt;
            dvd -= base;
        }
        res = ((dividend<0)^(divisor<0))? -res : res;
        return (res > INT32_MAX || res < INT32_MIN) ? INT32_MAX : res;
    }
};
```
```java []
class Solution {
    public int divide(int dividend, int divisor) {
        long dvd = Math.abs((long)dividend);
        long div = Math.abs((long)divisor);
        long res = 0;
        // dvd = div*2^2 + div*2^1+div*2^0
        // dvd/div = 2^2+2^1+2^0
        while(dvd >= div){
            long cnt=1;
            long base = div;
            while(dvd > (base<<1)){
                cnt <<= 1;
                base <<=1;
            }
            res += cnt;
            dvd -= base;
        }
        
        res = (dividend<0)^(divisor<0) ? -res: res;
        return (res > (long)Integer.MAX_VALUE || res < (long)Integer.MIN_VALUE) ? Integer.MAX_VALUE: (int)res;
    }
}
```
```python []
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        dvd, div = abs(dividend), abs(divisor)
        res = 0
        INT_MAX, INT_MIN = pow(2, 31)-1, -pow(2, 31)
        while dvd >= div:
            cnt, base = 1, div
            while dvd > (base<<1):
                cnt <<=1
                base <<=1
            res += cnt
            dvd -= base
        res = res if (dividend<0)^(divisor<0)==0 else -res
        return INT_MAX if res>INT_MAX or res<INT_MIN else res
```