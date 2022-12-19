### 解题思路

gcd

### 代码

```cpp
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)return true;
        if(x==0)return y==z;
        if(y==0)return x==z;
        int g=gcd(x,y);
        if(z>x+y)return false;
        if(abs(z-y)%g==0)return true;
        return false;
    }
};
```