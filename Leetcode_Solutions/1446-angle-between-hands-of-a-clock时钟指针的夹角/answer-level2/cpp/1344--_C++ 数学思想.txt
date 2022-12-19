### 解题思路
将问题转换为固定的数学公式：5.5x-30y即问题答案。

### 代码

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a=abs(5.5*minutes-30*hour);
        if(a>180) return 360-a;
        return a;
    }
};
```