### 解题思路
如果gcd(x,y)=d,则一定存在整数 a,b使得  ax+by=d成立

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
            if(x+y<z)
            return false;
            if(x==z||y==z||x+y==z)
            return true;

            return z%gcd(x,y)==0;
    }
};
```