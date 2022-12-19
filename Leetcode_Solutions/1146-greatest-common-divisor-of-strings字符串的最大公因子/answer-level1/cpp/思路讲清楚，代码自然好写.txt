- 既然要满足整除的性质，首先就要求出两个字符串长度的最大公约数`len`，这就是可能的最大公因子了
- 然后就去检查`str1[0,. len)`和`str2[0,. len)`中最大的一致子字符串的长度
- 最后再检查两个字符串是否由子字符串重复连接而成
```
class Solution {
public:
    int gcd(int m, int n) {
        if (n) return gcd(n, m%n);
        return m;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        int len = gcd(max(len1, len2), min(len1, len2));
        int pos = 0;
        while (pos < len && str1[pos] == str2[pos]) ++pos;
        if (pos == 0 || len % pos || !isValid(str1, pos) || !isValid(str2, pos)) return "";
        return str1.substr(0, pos);
    }
    
    bool isValid(const string& s, int pos) {
        int m = s.size();
        for (int i = pos, j = 0; i < m; ++i, ++j) {
            j %= pos;
            if (s[i] != s[j]) return false; 
        }
        return true;
    }
};
```
