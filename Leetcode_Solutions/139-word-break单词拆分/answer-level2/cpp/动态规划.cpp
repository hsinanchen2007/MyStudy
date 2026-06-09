### 解题思路
首先，在字符串s中出查找每一个wordDict中子串所在位置的末尾（所有位置），记录在字典iword中
例如s="abcaba",wordDict包含一个"ab"时，有iword[1] = {"ab"}, iword[4] = {"ab"}

然后，dp数组长为s.size()+1，dp[i]表示前i为字符可不可以拆
dp[i] = (i-1处是相匹配的子串的末尾) && dp[i - 对应子串的长度]。

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        map<int, vector<string>> iword;//保存以i为末尾的匹配子串vector
        for (string word : wordDict)
        {
            int stapos = 0;
            int pos;
            do
            {
                pos = s.find(word, stapos);//从s[stapos]开始查找word的位置
                stapos = pos + 1;   //下一次查找是从上次结果的下一位开始
                if (pos != -1)
                {
                    int last = pos + word.size() - 1;//word在s中的某一位置的尾部
                    //插入iword中
                    if (iword.count(last) == 0)
                    {
                        vector<string> poss;
                        poss.push_back(word);
                        iword.insert(pair<int, vector<string>>(last, poss));
                    }
                    else
                    {
                        iword[last].push_back(word);
                    }
                }
            }while (pos != -1);//上一轮找到了，继续找，否则没找到就跳出来
        }
        //dp[i]表示前i为字符可不可以拆
        for (int i = 1; i < dp.size(); i++)
        {
            if (iword.count(i - 1) > 0)//存在以i-1为末尾的、能匹配的word
            {
                for (int j = 0; j < iword[i-1].size(); j++) //遍历这些word
                {
                    string &w = iword[i-1][j];
                    dp[i] = dp[i - w.size()];
                    if (dp[i])//可以拆，不继续找
                    {
                        break;
                    }
                }
            }
            else//不可拆
            {
                dp[i] = 0;
            }
        }
        return dp[s.size()];
    }
};
```