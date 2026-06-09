### 解题思路
将特殊情况表示出来
    ①x为负数的时候，一定不是回文数；
    ②x为大于等于零的个位数时，一定是回文数；
    ③将x翻转，检验翻转后的结果obj是否与x相等，若相等，为true，反之为false

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
        return false;

        if(x>=0&&x<10)
        return true;

        long long obj=0, x1=x;
        while(x!=0)
        {
            int temp = x%10;
            obj =  obj*10+temp;
            x/=10;
        }

        if(obj==x1)
            return true;
        else
            return false;
    }
};
