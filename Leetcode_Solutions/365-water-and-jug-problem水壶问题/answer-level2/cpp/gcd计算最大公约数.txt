### 解题思路
使用gcd计算最大公约数，如果可以被约数整除，则可能为真。
如果两个水壶总量小于水量，则为假。

### 代码

```cpp
class Solution {
public:
    int gcd(int x, int y){
        if(x == 0 || y == 0){
            return x + y;
        }
        int z = x%y;
        while(x%y != 0){
            z = x%y;
            x = y;
            y = z;
        }
        return y;
    }

    bool canMeasureWater(int x, int y, int z) {
        if(z == 0){
            return true;
        }
        if(x + y == z){
            return true;
        }else if(x + y < z){
            return false;
        }else{
            return z%gcd(x, y) == 0;
        }
    }
};
```