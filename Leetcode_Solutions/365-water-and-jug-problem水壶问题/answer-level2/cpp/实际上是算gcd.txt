### 解题思路
经典数学问题，注意特判一些边缘情况

### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b) {
        return b ? gcd(b, a % b) : a;
    }

    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)return false;
        else if(z==0 or x + y == z)return true;
        else if(not x)return y==z;
        else if(not y)return x==z;
        else return not (z % gcd(x, y));
    }
};
```