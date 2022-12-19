假设s[i : j]为连续的相同字符，则以s[i : j]为中心向两侧扩展，直到s[i - k] != s[j + k]，则这时的最长回文子串为s[i - k + 1 : j + k - 1]，最长回文子串的长度为longest[i] = j - i + 2k - 1，全局的最长回文子串长度为max(longest[i])。

```
class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, longest = 0, len = 0, bias = 0;
        for (int i=0; i<s.size(); ++i) {
            // 当前字符和前一个字符相同则跳过
            if (i > 0 && s[i] == s[i-1]) continue;

            bias = 0;
            // 从当前字符开始，向后找到和当前字符相同的字符，作为回文串的中心
            for (int j=i; j<s.size()-1; ++j)
                if (s[j] == s[j+1]) ++bias;
                else break;
            // 第i轮循环可能找到的最长回文子串若不大于此前的最大值，则结束循环
            if ((s.size() - i)*2 - bias - 1 <= longest) break;
            // 从回文串的中心向两侧寻找
            for (len=1; len<i+1 && len<s.size()-i-bias; ++len) {
                if (s[i-len] != s[i+len+bias])
                    break;
            }
            // 计算当前最长回文子串的长度以及起始位置
            if (longest < len*2 - 1 + bias) {
                longest = len*2 - 1 + bias;
                begin = i - len + 1;
            }
        }
        return s.substr(begin, longest);
    }
};
```
