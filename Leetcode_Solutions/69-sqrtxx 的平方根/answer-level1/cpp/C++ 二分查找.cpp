### 解题思路
通过二分法查找均方根，注意上限不要溢出

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int a=0;
        int b=46340;
        int m;
        if(b*b<=x)
            return(b);
        if(x<46340)
            b=x;
        while(b>a)
        {
            m=(a+b)/2;
            if(m*m<x&&(m+1)*(m+1)<x)
                a=m;
            if(m*m>x)
                b=m;
            if(m*m<=x&&(m+1)*(m+1)>x)
                return(m);
            if((m+1)*(m+1)==x)
                return(m+1);
        }
        return(a);
    }
};
```