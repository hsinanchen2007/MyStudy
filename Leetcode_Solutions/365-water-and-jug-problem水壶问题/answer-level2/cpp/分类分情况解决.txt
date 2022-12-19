### 解题思路
暴力破解？

基本可能(x<y时) x y x+y x*2
其他可能：从m=y-x开始,若m<x则只有两种情况：m+y（m放小杯+y大杯） 和 m=m+y-x（m放小杯，大杯倒小杯余量）；
若m>=x,则只有一种情况m=m-x;
当m<=0时停止搜索



### 代码

```cpp
class Solution {
public:
    inline int mod1(int a,int b)
    {
        if(b==0)
        return a;
        else
        return a%b;
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x > y)
        {
            x+=y;
            y=x-y;
            x-=y;
        }
        if(x+y<z)
        return false;

        if(z==y || z==x || x+y==z || x*2==z)
        return true;

        int m=y-x;
        if(m==z) return true;
        while(m>0)
        {
            if(m>=x)
            {
                m=m-x;
                if(x==0) return false;
            }
            else
            {
                if(m+y==z) return true;
                else m=m+y-x;
            }
            if(m==z) return true;
        }
        return false;
    }
};
```