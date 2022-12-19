### 解题思路
二分

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        double left = 1, right = x;
        double tar;
        while (abs(x - tar * tar) > 0.1) {
            if (x - tar * tar > 0) {
                left = tar;
            } else {
                right = tar;
            }
            tar = (left + right) / 2;
        }

        return (int)tar;
    }
};
```