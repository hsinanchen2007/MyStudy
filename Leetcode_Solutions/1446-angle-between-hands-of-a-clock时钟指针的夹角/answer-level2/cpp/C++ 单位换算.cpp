### 解题思路
单位换算
![图片.png](https://pic.leetcode-cn.com/43dce73de71a0d8ef1101a77f90b7ce0e1963617f91e5f0aa49e0e9f6f1e3589-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double l1 = minutes;
        double l2 = (hour % 12) * 5 + minutes / 60.0 * 5;
        double angle = abs(l2 - l1) * 360.0 / 60;
        if (angle > 180) {
            return 360 - angle;
        } else {
            return angle;
        }
    }
};
```