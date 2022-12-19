### 解题思路
1.暴力求解
```C++ []
class Solution {
    bool check(string t,string s){
        int lenx = (int)s.length() / (int)t.length();
        string ans = "";
        for (int i = 1; i <= lenx; ++i){
            ans = ans + t;
        }
        return ans == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        for (int i = min(len1, len2); i >= 1; --i){ // 从长度大的开始枚举
            if (len1 % i == 0 && len2 % i == 0){
                string X = str1.substr(0, i);
                if (check(X, str1) && check(X, str2)) return X;
            }
        }
        return "";
    }
};
```
```python []
class Solution:
    def check (self, str_t, str_s):
        x = len(str_s)//len(str_t)
        ans = ''
        for i in range(1, x+1):
            ans += str_t
        return ans == str_s  
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        for i in range(min(len(str1), len(str2)), 0, -1):
            if (len(str1) % i) == 0 and (len(str2) % i) == 0:
                if self.check(str1[:i], str1) and self.check(str1[:i], str2):
                    return str1[:i]
        return ''
```
2.辗转相除法
新知识：求最大公约数的方法gcd
```C++ []
class Solution {
    bool check(string t,string s){
        int lenx = (int)s.length() / (int)t.length();
        string ans = "";
        for (int i = 1; i <= lenx; ++i){
            ans = ans + t;
        }
        return ans == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = (int)str1.length(), len2 = (int)str2.length();
        string T = str1.substr(0, __gcd(len1,len2)); // __gcd() 为c++自带的求最大公约数的函数
        if (check(T, str1) && check(T, str2)) return T;
        return "";
    }
};
```
```python []
class Solution:
    def check (self, str_t, str_s):
        x = len(str_s)//len(str_t)
        ans = ''
        for i in range(1, x+1):
            ans += str_t
        return ans == str_s  
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        i = math.gcd(len(str1), len(str2))
        if self.check(str1[:i], str1) and self.check(str1[:i], str2):
            return str1[:i]
        return ''
```

