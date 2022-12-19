```
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(const auto& s:words){
            if(lala(s,pattern)&&lala(pattern,s)){
                ans.push_back(s);
            }
        }
        return ans;
    }

    bool lala(const string& s,const string& pattern){
        if(s.size()!=pattern.size()){
            return false;
        }
        vector<int> v(26,-1);
        int size=s.size();
        for(int i=0;i<size;++i){
            if(v[pattern[i]-'a']==-1){
                v[pattern[i]-'a']=s[i]-'a';
            }
            else if(v[pattern[i]-'a']!=s[i]-'a'){
                return false;
            }
        }
        return true;
        
    }
};
```
