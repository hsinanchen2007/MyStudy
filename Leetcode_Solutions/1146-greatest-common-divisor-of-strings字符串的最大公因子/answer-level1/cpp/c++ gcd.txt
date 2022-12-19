### 解题思路

两个字符串之和前后拼接不相等，就是无因子。

然后取他们两个的gcd函数得到长度，然后截取字符串即可。
### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1+str2) != (str2+str1)) return "";
        return str2.substr(0,gcd(str1.length(),str2.length()));
    }
    int gcd(int a,int b) {
        if(a<b) return gcd(b,a);
        return a%b ? gcd(b,a%b) : b;
    }
};
```