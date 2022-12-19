### 解题思路
![image.png](https://pic.leetcode-cn.com/63cdabac954c2111b9246dd4e06c565bd846ce76ec3049589a6e5c66f1beb27e-image.png)



### 代码

```cpp
class Solution {
    int n;
    vector<string>res;
    unordered_map<int,set<int>>hash;
    string s;
    void dfs(int start, string temp)
    {
        if(start == n)
        {
            res.push_back(temp);
            return ;
        }
        for(auto end : hash[start])
        {
            if(start == 0)
            {
                dfs(end, s.substr(start, end - start));
            }
            else
            {
                dfs(end, temp +" " + s.substr(start, end - start));
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->n = s.size();
        this->s = s;
        unordered_set<string>m_set(wordDict.begin(), wordDict.end());
        vector<bool>dp(s.size() + 1, false);
        dp[s.size()] = true;
        for(int i = s.size(); i >= 1; i--)
        {
            if(dp[i] == true)
            {
                for(int j = 0; j < i; j++)
                {
                    if(m_set.count(s.substr(j, i - j)) == 1)
                    {
                        hash[j].insert(i);
                        dp[j] = true;
                    }
                }
            }
        }
        dfs(0, ""); //dfs用来连词
        return res;
    }
};
```