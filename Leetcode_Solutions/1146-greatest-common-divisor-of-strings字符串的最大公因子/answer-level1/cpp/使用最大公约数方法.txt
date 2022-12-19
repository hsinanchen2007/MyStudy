### 解题思路
1、首先判断是否存在这样的一个`X`,使`X`能整除`str1`和`str2`。若满足，则说明`str1`和`str2`是由若干个`X`组成的。区别在于`str1`和`str2`是由不同数量的`X`组成的，那么就有`str1 + str2 == str2 + str1`
2、由1可知，`str1`和`str2`可分割成若干个`X`。那么`X`的长度就是`str1.size()`和`str2.size()`的最大公约数。
假设`X`的长度为`l`，那`str1`和`str2`的长度为几倍的`l`。

这样应该比较容易理解。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        if (str1 + str2 != str2 + str1) return "";
        string X = str1.substr(0, gcd(str1.size(), str2.size()));
        return X;
    }
};
```