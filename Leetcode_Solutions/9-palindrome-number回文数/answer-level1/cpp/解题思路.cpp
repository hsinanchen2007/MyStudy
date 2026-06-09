### 解题思路
根据题意负数肯定不是回文数，因此我先判定了是不是负数。然后再将各位数颠倒，保存在sum中，最后再与原先数x比较。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return 0;
        long int a,sum=0;
        int b;
        a=x;
        while(a)
        {
           b=a%10;
           sum*=10;
           sum+=b;
           a=a/10;
        }
        if(sum==x)
        return 1;
        else 
        return 0;
    }
};
```