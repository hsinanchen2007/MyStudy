从零开始不是很方便直观，处理起来碍手碍脚，所以我们下面把0去掉，只需要把输入的n减1就好了（0只占了1位）

规律：
1   -   9， 占用 1×9位
10  -  99， 占用 2×90位
100 - 999， 占用 3×900位
可推而广之，全部N位数，占用N ×9 × pow(10,N-1) 位

举例, n = 2345 ， -1变成2344
digits表示处理的数字位数， start表示当前位数数字的起始（1,100,1000...）
digits = 1 时， n 减去 9
digits = 2 时， n 减去 2 × 90
digits = 3时，  n已经不够 3 × 900
所以，最后定位到的数字num是3位数，这个三位数是 100 + n / 3, 而 n % 3,则是num中的位置,
此处乃关键。



```
class Solution {
public:
    int findNthDigit(int n) 
    {
        n--;
        int digits = 1;
        long start = 1;
        while (digits < 11)
        {
            if (n >= 9*start*digits)
            {
                n-= 9*start*digits;
            }
            else
            {
                int num = start + n / digits;
                return to_string(num)[n % digits] - '0';
            }
            start *= 10;
            digits++;
        }
        return 0;
    }
};
```
