双指针，比加挪就完了
```
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res{""};
        for(string t:d){
            if(t.size() > res.size() || (t.size() == res.size() && t < res)){
                for(int i = 0, j = 0; i < t.size() && j < s.size(); j++){
                    if(s[j] == t[i]) i++;
                    if(i == t.size()) res = t;
                }
            }
        }
        return res;
    }
};
```
