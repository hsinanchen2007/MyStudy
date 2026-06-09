![image.png](https://pic.leetcode-cn.com/b72ee097caadd8e6de3ff53a7e1f17dde7048286787afdcc5bef51283f5b81b3-image.png)
```
class Solution {
public:
    long int abs_(long int i)
    {
        if(i > 0)
            return i;
        else
            return -i;
    }
    int divide(int dividend, int divisor) {
        long int dividend_ = dividend;
        long int divisor_ = divisor;
        bool reverse = false;
        if(dividend_ * divisor_ < 0)
        {
            reverse = true;
        }
        dividend_ = abs_(dividend_);
        divisor_ = abs_(divisor_);
        long int answer = 0;
        while(dividend_ >= divisor_)
        {
            int num = getNum(dividend_, divisor_);
            answer+= 1 << num;
            dividend_ -= divisor_ << num;
        }
        if(reverse)
            answer = -answer;
        else
            answer = answer;
        if(answer >= pow(2,31) - 1 || answer < -pow(2,31))
        {
            return pow(2,31) - 1;
        }
        else
        {
            return answer;
        }
    }
    int getNum(long int a, long int b)
    {
        for(int i = 0; i < 32; i++)
        {
            if(a < (b << i))
            {
                return i - 1;
            }
        }
        return 0;
    }
};
```
