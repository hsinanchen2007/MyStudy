```C++ []
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y <z) return false;
        int tmp;
        if(x == 0 || y==0) return z==0 || x+y == z;
         tmp = gcd(x, y);
        return z%tmp == 0;
    }
};
```

