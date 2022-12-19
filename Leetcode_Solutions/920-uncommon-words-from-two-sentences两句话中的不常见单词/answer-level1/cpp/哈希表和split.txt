### 解题思路
分别对A，B创建两个哈希表，记录词频，遍历哈希表比对即可

### 代码

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        vector<string> word[2]{split(A, ' '), split(B, ' ')};
        unordered_map<string, int> mp[2];
        for (auto s : word[0])
            mp[0][s]++;
        for (auto s : word[1])
            mp[1][s]++;
        vector<string> ans;
        for (auto it = mp[0].begin(); it != mp[0].end(); it++)
            if (it->second == 1 && mp[1][it->first] == 0) ans.push_back(it->first);
        for (auto it = mp[1].begin(); it != mp[1].end(); it++)
            if (it->second == 1 && mp[0][it->first] == 0) ans.push_back(it->first);
        return ans;
    }
    vector<string> split(string str, char ch)
    {
        vector<string> subs;
        for (int i = -1, k = 0; k < str.length(); )
        {
            while (str[k] == ch) k++;
            i++;
            subs.push_back("");
            while (str[k] != ch && k < str.length())
            {
                subs[i] += str[k];
                k++;
            }
            if (subs[i] == "") subs.pop_back();
        }
        return subs;
    }
};
```