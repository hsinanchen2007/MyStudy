所谓「快乐前缀」，就是在输入串中查找其自身的一个前缀（但不等于它自身）。这看起来与经典的字符串匹配问题很相似。以 `"ababab"` 为例，我们需要在去掉首个字符的串 `"babab"` 中查找是否有 `"ababab"` 的某个前缀的匹配。不难发现解存在：
```text
babab
 ababab
```

KMP 是一个容易想到的字符串匹配算法，但是原始的版本只有在模式串完全匹配文本中的一段时才算作匹配成功。这里，我们只需要文本的一个后缀与模式串的一个前缀相匹配就算成功，且题目所求的「最长快乐前缀」显然就是按此标准能够匹配上的首段（从左往右）文本。为了实现这个功能，我们只需要把 KMP 原来的成功条件（“模式串读到结尾”）改为“文本读到结尾”。

注意 KMP 算法的复杂度是 $O(m+n)$，其中 $m$ 和 $n$ 分别为文本和模式串的长度。本题中的模式串为输入串长度减一，由此整体复杂度依然是线性的。

参考实现：

```c++
class Solution {
    void computeNext(const string& a, vector<int>& next)
    {
         const int len = a.size();
         int i = 0, j = -1;
         while (i < len) {
            if (j == -1 || a[i] == a[j]) next[++i] = ++j;
            else j = next[j];
         }
    }

    int KMP(const string& src, const string& pat)
    {
        const int m = src.size();
        const int n = pat.size();
        
        vector<int> next(n + 1, -1);
        computeNext(pat, next);
        
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || src[i] == pat[j]) {
                i++;
                j++;
            } else j = next[j];
        }

        if (i == m) { // 文本读到结尾！
            return i - j; // 返回文本值匹配的后缀的起始下标
        }
        return -1;
    }

public:
    string longestPrefix(string s) {
        const int n = s.size();
        if (n == 1) return "";
        
        int k = KMP(s.substr(1), s);
        if (k == -1) return "";
        return s.substr(k + 1);
    }
};
```