### 解题思路
注意m如果是int可能会溢出

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x)
    {
        if (x <= 1) return x;
        int a = 1, b = x;
        long long m = a + (b - a) / 2;
        while (a < b)
        {
            if (m * m > x) b = m - 1;
            else if (m * m < x) a = m + 1;
            else return m;
            m = a + (b - a) / 2;
        }
        long long aa = (long long) a * a;
        return aa > x ? a - 1 : a;
    }
};
```