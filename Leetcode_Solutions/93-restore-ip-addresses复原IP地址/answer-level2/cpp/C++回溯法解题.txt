直接上代码，如下：
```
class Solution {
public:
    vector<string> ans;
    string tmpans;
    void dfs(string &s, int t, int num)
    {
        if (t>s.size() || num>4)
            return;
        if (t == s.size() && num == 4)
        {
            tmpans.pop_back();
            ans.push_back(tmpans);
            tmpans.push_back('.');
            return;
        }
        if (num == 4)
            return;
        for (int i = 3; i >= 1; i--)
        {
            if ((t + i)>s.size())
                continue;
            int n = atoi(s.substr(t, i).c_str());
            if (n>255 || (i>1 && s[t] == '0'))
                continue;
            tmpans += s.substr(t, i);
            tmpans.push_back('.');
            dfs(s, t + i, num + 1);
            for (int j = 0; j <= i; j++)
            {
                tmpans.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0);
        return ans;
    }
};
```
