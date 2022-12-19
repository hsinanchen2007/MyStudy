```
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size() || p.size() == 0) return res;
        unordered_map<char, int> m;
        for(int i = 0; i < p.size(); ++i){
            m[p[i]]++;
        }
        int i = 0, j = 0;
        while(j < s.size()){
            if(!m.count(s[j]) || !m[s[j]]){
                while(i < j && s[i] != s[j]){
                    m[s[i++]]++;
                }
                i++;
            }else{
                m[s[j]]--;
            }
            if(m.count(s[j]) && !m[s[j]] && (p.size() == (j - i + 1))){
                res.push_back(i);
            }
            j++;
        }
        return res;
    }
};
```
