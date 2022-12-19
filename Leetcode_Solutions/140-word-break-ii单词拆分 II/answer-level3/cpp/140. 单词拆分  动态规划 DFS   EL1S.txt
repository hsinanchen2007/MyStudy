这道题思路不难想，但是代码却改了好几次才通过，最主要的问题是会出现超时间/超内存
第一种方式：
利用动态规划--超时间限制，因为有很多没有利用到的状态也被计算了，这些状态也都被计算了下来
```
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<vector<string>>> dp(n, vector<vector<string>>(n));
        for(int len = 1; len <= n; len++)
        {
            for(int l = 0; l < n; l++)
            {
                int r = l + len - 1;
                if(r >= n) break;
                string sub = s.substr(l, r - l + 1);
                if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
                {
                    dp[l][r].push_back(sub);
                }
                for(int k = l; k < r; k++)
                {
                    if(dp[l][k].size() && dp[k + 1][r].size())
                    {
                        for(auto x: dp[l][k])
                            for(auto y: dp[k+1][r])
                            {
                                string tmp = x + " " + y;
                                dp[l][r].push_back(tmp);
                            }
                    }
                }
            }
        }

        vector<string> res;
        sort(dp[0][n - 1].begin(), dp[0][n - 1].end());
        for(auto x: dp[0][n - 1])
        {
            if(!res.size() || x != res.back())
                res.push_back(x);
        }
        return res;
    }
};
```
dp--超内存限制 原因是到最后了才发现最后面的拼不起来啊，那个恨，前面的都浪费了
```
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n);
        for(int i = 0; i < s.size(); i++)
        {
            string sub = s.substr(0, i - 0 + 1);
            if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end())
            {
                dp[i].push_back(sub);
            }


            for(int j = i; j > 0; j--)
            {
                string sub = s.substr(j, i - j + 1);//[j, i]
                if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end() && dp[j - 1].size())
                {
                    for(auto x: dp[j - 1])
                    {
                        dp[i].push_back(x + " " + sub);
                    }
                    
                }
            }
        }
        return dp[n - 1];
    }
};
```

dfs--先扫一次到最后看看能不能拼起来，如果能拼起来再拼起来，并且可以去利用set加快搜索速度
```
class Solution {
    string s;
    set<string> wordDict;
    map<int, vector<string>> mp;
    vector<int> v;
    void dfs(int start)
    {
        if(start == s.size())
        {
            v[start] = 1;
            mp[start] = {""};
            return;
        }
        if(v[start] != -1)//说明已经访问过了
        {
            return;
        }


        vector<string> res;
        for(int k = start; k < s.size(); k++)
        {
            string sub = s.substr(start, k - start + 1);
            if(wordDict.count(sub))
            {
                dfs(k + 1);
                if(v[k+1] == 0) continue;
                for(auto x: mp[k+1])
                {
                    if(x.size())
                        res.push_back(sub + " " + x);
                    else
                        res.push_back(sub);
                }
            }
        }
        if(res.size())
        {
            v[start] = 1;
            mp[start] = res;
        }
        else
        {
            v[start] = 0;
        }
        return;
    }
public:
    vector<string> wordBreak(string _s, vector<string>& _wordDict) {
        s = _s;
        for(auto x:_wordDict)
            wordDict.insert(x);
        v = vector<int>(s.size() + 1, -1);//-1没有搜索， 0 不行 1可以
        dfs(0);
        
        vector<string> tmp = mp[0];
        if(tmp.size())
            return tmp;
        else
            return vector<string>();
    }
};
```

