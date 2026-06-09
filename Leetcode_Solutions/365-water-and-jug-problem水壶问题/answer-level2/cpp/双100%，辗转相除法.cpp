```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)   return false;
        if(z == 0)  return true;
        if(x == 0)  return y==z;
        if(x < y)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        int k  = x % y;   //余数
        while(k != 0 )      //求最大公约数
        {
            x = y;
            y = k;
            k = x % y;
        }
        if(z % y == 0)  return true;
        else            return false; 
    }
};
```
