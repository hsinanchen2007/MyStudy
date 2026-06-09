
### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x==0||y==0)
            return z==0||z==x+y;
        if(x+y<z)
            return false;
        return z%gcd(x,y)==0;
    }
};
```