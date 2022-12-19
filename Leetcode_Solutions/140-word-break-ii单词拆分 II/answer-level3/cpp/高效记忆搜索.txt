```
class Solution {
public:
//执行用时 :16 ms, 在所有 C++ 提交中击败了91.82%的用户
//内存消耗 :11.2 MB, 在所有 C++ 提交中击败了77.24%的用户
//记忆每个位置后面可分的所有情况
    string s;
    int max_len,word_len;
    unordered_set<string> dict;
    unordered_map<int,vector<string>> mp;
    vector<string> res;
    vector<string> wordBreak(string S, vector<string>& wordDict) {
        dict = {wordDict.begin(),wordDict.end()};
        s = S;max_len = s.length();
        for(auto&it:wordDict) word_len = max(word_len,(int)it.length());
        return dfs(0);
    }
    vector<string> dfs(int site) {
        if(site==max_len) return vector<string>();
        if(mp.count(site)) return mp[site];
        vector<string> rec;
        string sub_s;
        for(int i=site;i<=site+word_len-1&&i<max_len;i++) {
            sub_s = s.substr(site,i-site+1);
            if(!dict.count(sub_s)) continue;
            auto v = dfs(i+1);
            if(i+1==max_len) rec.push_back(sub_s);
            for(int j=0;j<v.size();j++) rec.push_back(sub_s + " " + v[j]);
        }
        return mp[site] = rec;
    }
};
```
