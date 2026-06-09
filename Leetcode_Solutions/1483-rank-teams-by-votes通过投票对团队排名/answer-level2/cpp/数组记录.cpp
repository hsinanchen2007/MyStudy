### 解题思路
用一个pair记录每一个队投票情况，将所有pair组合成vector，然后进行排序
### 代码

```cpp
class Solution {
public:
    static bool cmp(pair<char, vector<int>> a, pair<char, vector<int>> b){
        vector<int>& tempa = a.second;
        vector<int>& tempb = b.second;
        for(int i = 0; i < 26; ++i){
            if(tempa[i] > tempb[i]){
                return true;
                break;
            }
            else if(tempa[i] < tempb[i]){
                return false;
                break;
            }
        }
        return false;
    }
    
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        int n = votes[0].size();
        vector<pair<char, vector<int>>> vo;
        
        for(int i = 0; i < 26; ++i){
            vector<int> ji(26, 0);
            vo.push_back(make_pair('A' + i, ji));
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int x = votes[i][j] - 'A';
                vector<int>& y = vo[x].second;
                y[j]++;
            }
        }
        stable_sort(vo.begin(), vo.end(), cmp);
        string ans;
        for(int i = 0; i < n; ++i){
            ans += vo[i].first;
        }
        return ans;
    }
};
```