枚举字符串的前缀，直到找到那个前缀的长度被两个字符串长度整除
```c++
class Solution {
public:
    bool check(string X, string str){
        int n = str.length() / X.length();
        string ret = "";
        for(int i = 0; i < n; i++){
            ret += X;
        }
        return ret == str;
    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        for(int i = min(n1, n2); i >= 1; i--){
            if(n1 % i != 0 || n2 % i != 0) continue;
            string X = str2.substr(0, i);
            if(check(X, str1) && check(X, str2)) return X;
        }
        return "";
    }
};
```
两个字符串的最大公因子串的长度一定为两个串长度的最大公约数gcd，只需要取出gcd前缀，然后判断该前缀是否可以组装成字符串即可
```c++
class Solution {
public:
    int GCD(int a, int b){
        if(a < b) swap(a,b);
        while(b != 0){
            int tmp = a % b;
            a = b; b = tmp;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int gcd = GCD(n,m);
        string ans1 = "", ans2 = "";
        int len1 = n / gcd, len2 = m /gcd;
        string cut = str1.substr(0,gcd);
        for(int i = 0; i < len1; i++) ans1 += cut;
        for(int i = 0; i < len2; i++) ans2 += cut;
        if(ans1 == str1 && ans2 == str2) return cut;
        return "";
    }
};
```
