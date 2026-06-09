***Talk is cheap. Show me the code.***
```cpp
/*
二分查找需要注意：
1、循环退出条件
2、mid 的取值
3、low 和 high 的更新
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int low = 2;
        int high = x>>1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            long tmp = (long)mid * mid;
            if (tmp < x) {
                low = mid + 1;
            }
            else if (tmp > x) { 
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return high;
    }
};

```