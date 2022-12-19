### 解题思路
假设回文数x=abcba
=>
    x=abc
    res=ab
    res*10=ab0
    **0 <= x-res*10 < 10 **

假设回文数x=abccba
=>
    x=abc
    res=abc
    **x==res**

### 代码

```csharp
public class Solution {
    public bool IsPalindrome(int x) {
        if(x<0 || (x%10==0 & x!=0))     //负数，以0结尾的正数
            return false;
        if(x < 10)                      //0~9
            return true;
        int res = 0;
        while(true)
        {
            res = res * 10 +(x % 10);
            x /= 10;
            if(x==res || (x-res*10 < 10 & x-res*10 >= 0))
                return true;
            if(x==0)
                return false;
        }
    }
}
```