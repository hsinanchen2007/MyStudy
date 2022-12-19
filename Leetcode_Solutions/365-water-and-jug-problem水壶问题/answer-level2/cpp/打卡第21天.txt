最大公约数的倍数就可以了

 ```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(x==0 && y==0) return z==0;
        int m = x>=y?x:y;
        int n = x>=y?y:x;
        return z % gcd(m,n) == 0;

    }
    int gcd(int x, int y){
      return  y==0?x:gcd(y,x%y);
    }
};
```
