### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double left=(double(hour)+double(minutes)/60)*30; //强制类型转换
        double right=double(minutes)*6;  //强制类型 
        double ans=abs(right-left);
        if(ans>180) return 360-ans;
        return ans;
    }
};
```