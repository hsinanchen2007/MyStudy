### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0 || x+y == z)
            return true;
        else if(x+y < z)
            return false;
        if(x > y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        if(x == 0)
            return y == z;
        int val = x;
        while(y%x != 0){
            val = y%x;
            y = x;
            x = val;
        }
        return z%val == 0;
    }
};
```