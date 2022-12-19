### 代码

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(360-abs(hour*30-minutes*5.5),abs(hour*30-minutes*5.5));
    }
};
```