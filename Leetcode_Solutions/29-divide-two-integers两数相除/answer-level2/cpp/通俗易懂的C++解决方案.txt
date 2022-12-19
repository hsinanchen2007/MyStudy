### 解题思路
1.单独处理除数为1和-1的情况
2.解题思路是使被除数为负，除数为正，被除数+除数>0 结束；
    2.1确定结果的正负，使被除数为负，除数为正
    2.2单独处理除数为int型下边界的情况；
    2.3找到 -除数>被除数 的最大除数
    2.4开始处理，每当 被除数+除数>0 时，除数右移一位，相当于除2，只到除数大于函数传入的除数结束；

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1)return dividend;
        if(divisor == -1)
        {
            if(dividend == 0x80000000)return 0x7FFFFFFF;
            else return -dividend;
        }
        bool isPos = true;
        if(dividend < 0)isPos = !isPos;
        else dividend = -dividend;
        if(divisor < 0)
        {
            isPos = !isPos;
            if(divisor == 0x80000000 && dividend == 0x80000000)return 1;
            if(divisor == 0x80000000 && dividend > 0x80000000)return 0;
            divisor = -divisor;
        }
        int mul = 1;
        int tempDivisor = divisor;
        while(tempDivisor <= 0x7FFFFFFF >> 1 && -tempDivisor >= dividend)
        {
            tempDivisor =  tempDivisor << 1;
            mul =  mul << 1;   
        }
        if(tempDivisor > divisor)
        {
            tempDivisor = tempDivisor >> 1;
            mul = mul >> 1;
        }
        int result = 0;
        while(tempDivisor >= divisor)
        {
            while(dividend + tempDivisor <= 0)
            {
                dividend += tempDivisor;
                result = result + mul;
            }
            tempDivisor = tempDivisor >> 1;
            mul = mul >> 1;
        }
        if(isPos)
            return result;
        else return -result;
        
    }
};
```