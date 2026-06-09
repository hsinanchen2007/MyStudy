看了他人评论发现，大部分都是无法分割的情况，所以可以先使用[139 word-break](https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-you-hua-by-joy-teng/) 判断一下是否可分，然后再回溯。
```
// Time 4ms, 100%, Space 10.1MB, 89%
class Solution {
    void backtrack(string &s, int i, unordered_set<int> &lens, 
        unordered_set<string> &dict, string &t, vector<string> &vs){
        if(i==s.length()){
            t.pop_back();
            vs.push_back(t);
            return;
        }
        for(const int &l:lens){
            if(i+l>s.length()) continue;
            string w=s.substr(i,l);
            if(dict.count(w)){
                w=t+w+" ";
                backtrack(s,i+l,lens,dict,w,vs);
            }
        }
    }
    bool wordBreak(string s, unordered_set<string> &dict, unordered_set<int> &lens){
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1; i<=s.length(); ++i){
            for(const int &l:lens){
                if(i>=l && dp[i-l] && dict.count(s.substr(i-l,l))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
public:
    vector<string> wordBreak(string s, vector<string>& words) {
        vector<string> vs;
        unordered_set<string> dict(words.begin(),words.end());
        unordered_set<int> lens;
        for(const string &word:dict)
            lens.insert(word.length());
        if(!wordBreak(s,dict,lens)) return vs;
        string t;
        backtrack(s,0,lens,dict,t,vs);
        return vs;
    }
};
```
