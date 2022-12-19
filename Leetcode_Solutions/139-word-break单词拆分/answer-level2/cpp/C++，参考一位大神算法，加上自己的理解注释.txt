### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       //动态规划，dp[i]表示字符串 s 的前 i 个字符能否拆分成 wordDict
       vector<bool> dp(s.size() + 1, false);
       //使用unordered_set（未排序的set加快访问wordDict速度）
       unordered_set<string> wd(wordDict.begin(), wordDict.end());
       dp[0] = true;
       //获取wordDict最长单词的长度
       int maxwordLength = 0;
       for(auto str : wordDict)
       {
           maxwordLength = max(maxwordLength, (int)str.size());
       }
       for(int i = 1; i <= s.size(); i++)
       {
           for(int j = max(i - maxwordLength, 0); j < i; j++)
           {
               //dp[j] = true, 表示 s的 前 j 个字符能拆分成 wordDict中单词
               //wd.find(s.substr(j, i - j)) != wd.end()表示 s.substr(j, i - j)
               //也是 wordDict中某个单词
               //则 s 的 前 i 个单词 可以拆成 wordDict 中的单词
               if(dp[j] && wd.find(s.substr(j, i - j)) != wd.end())
               {
                   dp[i] = true;
                   break;    
               }
           }
       } 
       return dp[s.size()];
    }
};
```