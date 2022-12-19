### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y){
            return false;
        }
        if(z==0 || z%(gcd(x,y))==0){
            return true;
        }
        return false;
    }
};
```