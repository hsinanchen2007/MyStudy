### 解题思路
C++纯新人刚学，之前四题都看答案的，这题是人生第一次自己做出来题目。
思路：观察子串，回文字数要么是偶数个，那么类似cbaabc这种中间是aa的；要么是奇数个，类似是cbabc中间是bab型的，仅此两种。
所以用for先找偶数型（aa)回文，找s[i]=s[i+1]，找到后再往两边推，直到s[i-len]==s[i+1+len]不等为止，记录此子串的位置和长度，最后进行长度比较。
再找s[i]=s[i+2]，即找奇数型（aba）回文，找到后处理同上。
ps:第一次提交没有通过，因为单个"a"的回文就是自己本身，"abcd"最长回文子串也是任意单个字母。按我的方法就没有输出。所以最后加了句如果max=0，即奇数型偶数型两种回文都没找到，就直接输出第一个字母。
执行用时 :20 ms, 在所有 C++ 提交中击败了90.14%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
蠢办法，没想到运行结果还是相当不错的，瞬间有点信心了。。
### 代码

```cpp
class Solution {
public:
string longestPalindrome(string s) 
{
    const int slen = s.length();
    int i,t;
    int max = 0;
    t = 0;
    for (i = 0; i < slen; i++)
    {
        if(s[i]==s[i+1])
            {
                int hlen=1;
                while((i-hlen>=0) && (i+1+hlen<=slen-1)&&(s[i-hlen]==s[i+1+hlen]))
                    hlen++;
                if (2 * hlen > max)
                {
                    max = 2 * hlen;
                    t = i-hlen+1;
                }
            }
    }
    for (i = 0; i < slen-1; i++)
    {
        if (s[i] == s[i + 2])
        {
            int hlen = 1;
            while ((i - hlen >= 0) && (i + 2 + hlen <= slen-1) && (s[i - hlen] == s[i + 2 + hlen]))
                hlen++;
            if (2 * hlen + 1 > max)
            {
                max = 2 * hlen + 1;
                t = i-hlen+1;
            }
        }
    }
    if (max==0)
        return s.substr(0,1);
    else
        return s.substr(t, max);
}
};
```