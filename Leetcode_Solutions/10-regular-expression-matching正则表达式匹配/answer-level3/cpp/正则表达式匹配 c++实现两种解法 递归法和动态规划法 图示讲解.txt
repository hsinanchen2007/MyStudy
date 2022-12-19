![10.mp4](d2139975-48cb-43b3-99da-a4d843f705fc)

<![1.jpg](https://pic.leetcode-cn.com/5ee55846cb1578b8f0b0730e6a8046a9b79ebb25b9e5c55d10e0e9cc7c45cee0-1.jpg),![2.jpg](https://pic.leetcode-cn.com/a512ea46bdba9f1369d3eb9d88f9471ef76e3f300647f6587960d906903e5daa-2.jpg),![3.jpg](https://pic.leetcode-cn.com/99a662908e79a7258a907b013dc532d32930b9f69dd9884bb522c340bd69793a-3.jpg),![1.jpg](https://pic.leetcode-cn.com/7735cd17106c01eb0c31e80f106e1e7e8ed278751a26f097b2a866a1f0a0e724-1.jpg),![2.jpg](https://pic.leetcode-cn.com/30497c063e97467379c082c53f846991044070f337581e5f3393d5fc2705bf72-2.jpg),![3.jpg](https://pic.leetcode-cn.com/523def4ec6670ab67f5289c916f61b4f644dc24bbd67c60c812cf5f312d23889-3.jpg),![4.jpg](https://pic.leetcode-cn.com/e8f0f5838a2cabdf2ebc545e776b6b2b1cfcb5da5d108a99d2bf164bc48a40de-4.jpg)>

```cpp [-C++]
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        if ('*' == p[1])
        {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        }
        else
        {
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/8a927ec2089c222430eb0b93f860b05b88f048162f2ee5f06e54eb168c105ee7-1.jpg),![2.jpg](https://pic.leetcode-cn.com/fa359262b6635914530b01ee87ef95953d69cfc06f343bbbd5b0ba30e0079f12-2.jpg),![3.jpg](https://pic.leetcode-cn.com/317513f185a581b4d8cae074b932d7540ca3986b58df5f19949d07bd57dd0c2a-3.jpg),![1.jpg](https://pic.leetcode-cn.com/405743445191202c5d8dc6ee04ead856a9d307163cee398816cb0221f5f1326e-1.jpg),![2.jpg](https://pic.leetcode-cn.com/b337e1bf5fb37a79be7d4c2f4d756114e17f939165d16576fb10da5044a43dc5-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f3b3e1fffbccd62e23e675a8a87f63c6b7d1818b03a630fac7e255c786b8c0f4-3.jpg),![4.jpg](https://pic.leetcode-cn.com/b104670226ad2a2cc5c93c2af6b151ca56089543ab7439fb5ed847f116abfe28-4.jpg),![5.jpg](https://pic.leetcode-cn.com/cc046150426e390fea77e505af4eb1ba8031bc6c34ca8a38935a7bebcbf50af0-5.jpg),![6.jpg](https://pic.leetcode-cn.com/9a57db4f9aa89584ea95b76ae33c171276c0b7bf5071c21082cc96b7a21c6295-6.jpg),![7.jpg](https://pic.leetcode-cn.com/52f49e65754df7f6da1b299fc4d3b4cdd6a12652d66e1d9613b70d6c620f6beb-7.jpg),![8.jpg](https://pic.leetcode-cn.com/bb9526f20c9f8632238bff4ca27525b6c4457cd0b25a95398cd77667e9f1606a-8.jpg),![9.jpg](https://pic.leetcode-cn.com/b2f2be0cda2824039d16a000c7042588bca35d1c6e7acd0138c189a64a21945e-9.jpg),![10.jpg](https://pic.leetcode-cn.com/d26b98bd51caa20ee4657d1854399f5907c3080b78657651ce60d4e3841b06c1-10.jpg)>

```cpp [-C++]
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void print(vector<vector<bool>> store);

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sSize = int(s.size());
        int pSize = int(p.size());
        if (p.empty())
        {
            return s.empty();
        }
        vector<bool> tmpVec(pSize + 1, false);//dp大小应该比s，p的size大1
        vector<vector<bool>> dp(sSize + 1, tmpVec); //dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
        dp[0][0] = true;
        if (sSize != 0 && (p[0] == s[0] || p[0] == '.'))
        {
            dp[1][1] = true;
        }
        if (p[0] == '*')
        {
            dp[0][1] = true;
        }
        //初始化情况：s为空，p为.*.*的情况
        for (int i = 1; i < pSize; i++)
        {
            if (p[i] == '*' && dp[0][i - 1] == true)
            {
                dp[0][i + 1] = true;
            }
        }

        for (int i = 0; i < sSize; i++)
        {
            for (int j = 1; j < pSize; j++)
            {
                if (p[j] == '.' || p[j] == s[i])
                { //如果是任意元素 或者是对于元素匹配
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if (p[j] == '*')
                {
                    //caa cb* -> caa c
                    if (p[j - 1] != s[i] && p[j - 1] != '.')
                    { //如果前一个元素不匹配 且不为任意元素
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    }
                    else
                    {
                        //caa c.* -> ca c.*
                        //caa ca* -> ca ca*
                        //ca ca* -> ca ca / c ca*
                        //ca ca*a* -> ca ca*
                        dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j - 1]);// || dp[i + 1][j]不需要
                    }
                }
            }
        }
        //print(dp);
        return dp[sSize][pSize];
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/eed00f971a2dfc23edcad8141b8fbfe2d037ce38142036f247ef1ff7cce3db53-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75917979
