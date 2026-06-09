```
class Solution {
public:
    int helper(unordered_map<string,int> &dp,vector<vector<int>> & dict,string target){
        int ans = INT_MAX;
        vector<int> count(26,0);
        
        if(dp.count(target)){
            return dp[target];
        }
        for(auto c : target){
            count[c-'a']++;
        }
        
        for(int i = 0;i < dict.size(); ++i){ 
            if(dict[i][target[0]-'a'] == 0){
                continue;
            }
            string str;
            for(int j = 0;j < 26; ++j){
                if(count[j] > dict[i][j]){
                    str += string(count[j] - dict[i][j],'a'+j);
                }
            }
            int res = helper(dp,dict,str);
            if(res >= 0){
                ans = min(ans,res+1);
            }
        }
        
        if(ans == INT_MAX){
            ans = -1;
        }
        dp[target] = ans;
        
        return ans;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> dict(n,vector<int>(26,0));
        unordered_map<string,int> dp;
     
        for(int i = 0;i < n; ++i){
            for(auto c : stickers[i]){
                dict[i][c-'a']++;
            }
        }
        dp[""] = 0;
        
        return helper(dp,dict,target);
    }
};
```