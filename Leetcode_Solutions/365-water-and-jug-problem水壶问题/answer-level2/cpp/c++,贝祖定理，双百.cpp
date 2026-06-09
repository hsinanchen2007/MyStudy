### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int d=gcd(x,y);
        if(!d&&(z==x+y))return 1;
        else if(d&&!(z%d)&&z<=x+y)return 1;
        return 0;
       }
};

```