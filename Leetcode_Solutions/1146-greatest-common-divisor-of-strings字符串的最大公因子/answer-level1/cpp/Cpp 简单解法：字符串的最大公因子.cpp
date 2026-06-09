![image.png](https://pic.leetcode-cn.com/3f37b5b66b1f466db51fe15f86c67daa21aecf6289ac4b439081c2de1162dbed-image.png)

思路和 [1071. 字符串的最大公因子 -- by @王德福](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1071-zi-fu-chuan-de-zui-da-gong-yin-zi-by-wonderfu/) 一样

参考大佬的解法，直接判断 `str1 + str2 != str2 + str1` 即可验证两个串是否有 gcd（之前是循环比较子串）

&nbsp;
```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        // gcd
        int x = str1.size(), y = str2.size();
        while (x^=y^=x^=y%=x);
        return str1.substr(0, y);
    }
};
```
