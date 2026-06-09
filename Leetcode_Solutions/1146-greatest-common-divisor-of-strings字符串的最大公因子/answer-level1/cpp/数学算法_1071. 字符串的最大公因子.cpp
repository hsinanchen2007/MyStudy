### 解题思路一 数学算法
    /*
     * 方法1 数学算法
     *
     * 数学公式中求两个数a,b的最大公约数的算法是：
     * gcd = (a, b) ==> (0 == b ? a : gcd(b, a % b))
     *
     * 如果字符串str1与str2有公因子"abc"，那么str1有m个"abc"的重复，
     * str2有n个"abc"的重复，将str1与str2连接起来就是m+n个"abc"，
     * 而str2连接str1的n+m个"abc"与之相等。
     * 所以如果 str1+str2 == str2+str1 相等，表示str1与str2有最大公因子。
     * 在确定存在最大公因子的情况下，最大公因子是长度为
     * gcd(str1.length(), str2.length())的字符串。
     * */
### 代码

```cpp
std::string gcdOfStrings(std::string str1, std::string str2) {
    // 判断str1与str2是否有最大公因子
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    // 最大公因子是长度为std::__gcd(str1.length(), str2.length())的子串
    std::string gcdStr = str1.substr(0, std::__gcd(str1.length(), str2.length()));

    return gcdStr;
}
```

### 解题思路二 枚举法
    /*
     * 方法2 枚举法
     *
     * 枚举的方法即从较短的字符串开始取子串，将子串与字符串str1、str2比较，
     * 判断该子串累加k次后是否等于字符串str1或str2，
     * 一直比较找到最大公因子串。
     * 借鉴方法一对枚举进行优化，可以直接使用str1,str2最大公因长度的子串，
     * 对字符串str1和str2进行判断。
     * */
### 代码

```cpp
std::string gcdOfStrings2(std::string str1, std::string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    // 取最大公因长度的子串
    std::string subStr = str1.substr(0, std::__gcd(len1, len2));

    // 判断该子串是否满足str1和str2
    if (check(subStr, str1) && check(subStr, str2)) {
        return subStr;
    }

    return "";
}

bool Solution1071::check(std::string subStr, std::string str) {
    // 求倍数k
    int len = str.length() / subStr.length();
    std::string res = "";

    // 对子串进行k次累加
    for (int i = 0; i < len; i++) {
        res = res + subStr;
    }

    // 累加后的字符串是否与比较字符串相等
    return res == str;
}
```