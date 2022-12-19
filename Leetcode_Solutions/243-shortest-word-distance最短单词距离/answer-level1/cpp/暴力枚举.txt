```
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> res, ccc;
        int ans = INT_MAX;
        for(int i = 0; i < words.size(); i++) if(words[i]==word1) res.push_back(i);
        for(int i = 0; i < words.size(); i++) if(words[i]==word2) ccc.push_back(i);
        for(auto i: res){
            for(auto j: ccc) ans = min(ans, abs(i-j));
        }
        return ans;
    }
};
```
