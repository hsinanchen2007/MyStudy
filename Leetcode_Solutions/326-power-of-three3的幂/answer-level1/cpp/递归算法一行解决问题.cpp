三种情况
1、小于等于0
2、等于1
3、大于0
递归：n不断余3，除以3，余数z始终为0，则是3的幂
否则不是。
```
class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0)
            return false;
        else if(n == 1)
            return true;
        else
            return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};
```
