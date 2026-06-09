典型的背包问题，用位图实现，递推公式dp[x|y] = min(dp[x|y],dp[x] + dp[y])
```
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int full = 1<<n;
        unordered_map<string,int> skills;
        vector<int> dp(full,-1);
        unordered_map<int,vector<int>> team;
        
        /*initial*/
        for(int i = 0;i < n; ++i){
            skills[req_skills[i]] = i;
        }
        
        dp[0] = 0;
        team[0] = vector<int>();
        
        for(int i = 0;i < people.size(); ++i){
            int idx = 0;
            for(auto s : people[i]){
                if(skills.count(s)){
                    idx = idx|(1<<skills[s]);
                }
            }
            for(int j = 0;j < full; ++j){
                if(dp[j] >= 0){
                    int x = j|idx;
                    if(dp[x] == -1 || dp[x] > dp[j] + 1){
                        dp[x] = dp[j] + 1;
                        team[x] = team[j];
                        team[x].push_back(i);
                    }
                }
            }
        }
        
        return team[full-1];
    }
};
```