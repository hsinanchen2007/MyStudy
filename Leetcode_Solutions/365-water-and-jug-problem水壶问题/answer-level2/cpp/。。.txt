### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z<0||z>x+y)
        return false;
        if(!z) return true;
        int g;
        if(x==0||y==0)
            g=x+y;
        else
            g=gcd(x,y);
        return !(z%g);
    }
    int gcd(int a,int b)
    {
        if(a%b==0)
            return b;
        return gcd(b,a%b);
    }

};
```