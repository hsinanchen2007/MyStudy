### 解题思路
采用无序map防止超时，map的键是要排序的字母，值是一个不定长数组，第i个表示排名第i，第i个的值表示该字母排名第i出现次数，最后写个自定义排序

### 代码

```cpp
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char,vector<int>>p;
        for(int i=0;votes[0][i];i++)p[votes[0][i]].resize(votes[0].size());
        for(const string& vote:votes)
        {
            for(int i=0;vote[i];i++)++p[vote[i]][i];
        }
        using node=pair<char,vector<int>>;
        vector<node>v(p.begin(),p.end());
        sort(v.begin(),v.end(),[](const node&a,const node& b){return a.second>b.second||(a.first<b.first&&a.second==b.second);});
        string ans;
        for(const node&it:v)ans+=it.first;
        return ans;
    }
};
```