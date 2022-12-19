既然没有禁止使用数学库求幂函数，为什么不用？求二次方根（平方根），不就是求它的二分之一次幂？

#include<cmath>
class Solution
{
public:
    int mySqrt(int x)
    {
        if (!x)
            return 0;
        x = (int)std::pow(x, 0.5);
        return x;
    }
};

12行的事情，既然分级是简单难度就不要自己给自己找麻烦了吧。
