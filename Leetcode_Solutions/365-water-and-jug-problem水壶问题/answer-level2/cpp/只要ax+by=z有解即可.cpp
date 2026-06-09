### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)return false;
        if(x+y==z)return true;
        if(x==0||y==0)return x==z||y==z;
        return z%gcd(x,y)==0;
    }
    int gcd(int a,int b){
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
};
```