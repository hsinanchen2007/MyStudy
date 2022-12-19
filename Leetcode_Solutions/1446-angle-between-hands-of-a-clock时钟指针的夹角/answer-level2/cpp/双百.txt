### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=(double)hour+(double)minutes/60;
        if(h>12)h=h-12;
        double an1=h/12*360;
        double an2=(double)minutes/60*360;
        double ang;
        if(an2-an1>0){
            ang=an2-an1;
        }
        else{
            ang=an1-an2;
        }
        if(ang>180){
            ang=360-ang;
        }
        return ang;
    }
};
```