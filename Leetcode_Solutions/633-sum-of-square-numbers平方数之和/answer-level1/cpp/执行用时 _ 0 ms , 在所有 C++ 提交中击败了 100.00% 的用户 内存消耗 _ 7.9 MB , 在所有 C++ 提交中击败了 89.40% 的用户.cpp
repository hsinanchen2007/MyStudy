判断是否为平方数，只需从设置两个变量left和right
初始值分别为0和(long)sqrt(c),扫描一遍即可。

```
class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        long left = 0;
        long right = (long)sqrt(c);
        while(left <= right)
        {
            long sum = left * left + right * right;
            if(sum == c)
                return true;
            else if(sum > c)
                right--;
            else
                left++;
        }
        return false;
    }
};
```
