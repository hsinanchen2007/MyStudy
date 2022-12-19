1. 统计所有的words的最小字母的频次，利用二分查找即可得到结果
```
class Solution {
public:
    int query(string a){
        vector<int> cnt(26,0);
        
        for(int i = 0;i < a.size(); ++i){
            cnt[a[i]-'a']++;
        }
        for(int i = 0;i < 26; ++i){
            if(cnt[i] > 0){
                return cnt[i];
            }
        }
        
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        vector<int> ans(n,0);
        vector<int> copy;
        
        for(int i = 0;i < words.size(); ++i){
            copy.push_back(query(words[i]));
        }
        sort(copy.begin(),copy.end());
        for(int i = 0;i < queries.size(); ++i){
            auto it = upper_bound(copy.begin(),copy.end(),query(queries[i]));
            ans[i] = copy.end() - it;
        }
        
        return ans;
    }
};
```