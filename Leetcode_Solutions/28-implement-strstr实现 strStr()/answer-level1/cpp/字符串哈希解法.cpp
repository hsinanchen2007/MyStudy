![微信图片_20200215172012.png](https://pic.leetcode-cn.com/fb244037c119a082d4deffafe25af0ebaf1732cb5e2eb3765280dc1d3687b02b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200215172012.png)

翻了翻没看到字符串哈希的题解，就写了一下。
算法就是通过哈希函数把长度为m的目标串哈希成一个整数，然后与模式串中每个长度为m的子串的哈希值比较，数值相同则(大概率)匹配成功
模式串中长度为m的子串的哈希值是可以O(1)递推的
```
class Solution {
public:
    int strStr(string haystack, string needle){
        if (needle.empty()) return 0;
        if (haystack.empty())
            return -1;
        static const int base = 31;
        static const int mod = (int)2e7 + 3;
        int n = haystack.size(), m = needle.size();
        int nowHash = haystack[0], hash = needle[0];
        int *p = new int[m];
        p[0] = 1;
        int ans = -1;
        for (int i = 1; i < m; ++i)
        {
            nowHash = (nowHash * base + haystack[i]) % mod;
            hash = (hash * base + needle[i]) % mod;
            p[i] = p[i-1] * base % mod;
        }
        if (nowHash == hash)
            ans = 0;
        else
            for (int i = m; i < n; ++i)
            {

                nowHash = ((nowHash - p[m-1] * haystack[i-m]) % mod + mod) % mod;
                nowHash = (nowHash * base + haystack[i]) % mod;
                if (nowHash == hash)
                {
                    ans = i - m + 1;
                    break;
                }
            }
        delete[] p;
        return ans;
    }
    
};
```
