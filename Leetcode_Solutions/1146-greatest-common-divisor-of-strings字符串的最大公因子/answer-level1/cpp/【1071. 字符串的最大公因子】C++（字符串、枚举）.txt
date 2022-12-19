### 解题思路
**字符串的最大公因子的长度必为字符串长度的最大公约数**
注：C++使用`__gcd(a, b)`计算最大公约数
### 代码

```cpp
class Solution {
    // 方法：求最大公约数，遍历
    // 子串检查
    int check_substr(string s, string t, int len_s, int len_t){
        if(len_s%len_t != 0)
            return 0;
        int it = len_s/len_t;
        string res = "";
        for(int i = 0; i<it; i++){
            res += t;
        }
        return res == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        int len_gcd = __gcd(len1, len2);   // 最大公约数
        string t = str1.substr(0, len_gcd);  //子串
        if(check_substr(str1, t, len1, len_gcd) && check_substr(str2, t, len2, len_gcd))
            return t;
        else
            return "";
    } 
};
```

### 解法二：数学方法
**可以证明：`str1 + str2 == str2 + str1`是存在最大公因子的充要条件；
最大公因子即`str1.substr(0, __gcd(len1(), len2()))`**
```
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); 
    }
};
```
