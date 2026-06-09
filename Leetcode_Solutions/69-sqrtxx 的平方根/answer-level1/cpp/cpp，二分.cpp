### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }
        int first = 1, second = x / 2;
        while (first <= second) {
            int mid = first + (second - first) / 2;
            int val = x / mid;
            if (mid < val) {
                first = mid + 1;
            } else if (mid == val) {
                return mid;
            } else {
                second = mid - 1;
            }
        }
        int val = x / first;
        if (first <= val) {
            return first;
        }
        return first - 1;
    }
};
```