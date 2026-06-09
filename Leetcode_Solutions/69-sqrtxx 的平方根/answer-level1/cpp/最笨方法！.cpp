
使用if和for来解题！！！！！
```cpp
class Solution {
public:
    int mySqrt(int x) 
    {
        long int x1;
        if(x==1)
        {
            x1=1;
        }
        else if(x==0)
        {
            x1=0;
        }
        else
        {
            for(x1=1;(x1+1)*(x1+1)<=x;x1++)
            {}
        }
        return x1; 
    }
};
```