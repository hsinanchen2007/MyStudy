### 解题思路


### 代码

```cpp

class Solution {
public:
struct score{
    char id;
    int v[26];
}s[26];
    string rankTeams(vector<string>& votes) {
        for(auto t : votes){
            for(int i = 0;i < t.size();++i){
                s[t[i] - 'A'].v[i] ++;
                s[t[i] - 'A'].id = t[i];
            }
        }

        sort(s, s+26, [](auto& a, auto& b){
            for(int i = 0;i < 26;++i){
                if(a.v[i] == b.v[i])
                    continue;
                return a.v[i] > b.v[i];
            }
            return a.id < b.id;
        });
        string ans = "";
        for(int i = 0;i < votes[0].size();++i){
            ans += s[i].id;
        }
        return ans;
    }
};
```