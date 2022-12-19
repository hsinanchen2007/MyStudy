### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double res = 1;
        for (int i = 1; i <= n; i++) {
            res = res/i + (1-res)*(i-1)/i;
        }
        return res;
    }
};
```