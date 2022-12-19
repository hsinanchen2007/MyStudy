### 解题思路
1. 直接对答案可能存在的区间进行二分 => 二分答案
2. 注意：判断区间的时候一个小技巧： mid * mid == x 中使用乘法可能会溢出，写成 mid == x / mid 即可防止溢出，不需要使用long或者BigInteger。

### 代码

```cpp
class Solution 
{
public:
    int mySqrt(int x) 
    {
        if (x < 0) return -1;
        if (x == 0) return x;

        int start = 1;
        int end = x;

        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;

            if (mid == x / mid) return mid;
            else if (mid < x / mid) start = mid;
            else end = mid;
        }

        if (x / end < end) return start;
        else return end;
    }
};
```