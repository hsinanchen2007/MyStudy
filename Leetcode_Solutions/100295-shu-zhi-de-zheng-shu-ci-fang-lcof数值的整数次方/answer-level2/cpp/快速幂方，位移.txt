### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) 
    {
        double num=1;
        long N=n;
        if (N < 0)
        {
            N=-N;
        }
        while (N)
        {
            if (N&1 == 1)
                num=num*x;
            x *= x;               
            N >>= 1;;
        }
        return n > 0 ? num:1/num;
    }
};
```