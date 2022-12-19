### 解题思路
![image.png](https://pic.leetcode-cn.com/d115a4e7989ecc07a7434650e0c3362b44537cdfb1a960d1ceef67a9a148516e-image.png)

### 代码

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a1=(hour%12)*30+30*static_cast<double>(minutes)/60;
        double a2=6*static_cast<double>(minutes);
        double a=a1>a2?a1-a2:a2-a1;
        if(a>180)
        a=360-a;
        return a;
    }
};
```