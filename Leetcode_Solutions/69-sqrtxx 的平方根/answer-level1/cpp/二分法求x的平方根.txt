### 解题思路
用二分法求解。

while循环的条件，将low和up分别取整，如果它们相等，而平方根一定位于low和up之间，本题要求只保留整数部分，小数部分舍去，所以平方根即将此刻的mid取整即可。

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        double low = 0;
        double up = x / 2.0 + 1.0;
        double mid;
        while (int(low) != int(up))
        {
            mid = (low + up) / 2.0;
            if (mid * mid > x)
                up = mid;
            else if (mid * mid < x)
                low = mid;
            else
                return int(mid);
        }
        return int(mid);
    }
};
```