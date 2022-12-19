```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(auto s:words){
            string base;
            if(base1.find(tolower(s[0]))!=string::npos) base=base1;
            if(base2.find(tolower(s[0]))!=string::npos) base=base2;
            if(base3.find(tolower(s[0]))!=string::npos) base=base3;
            bool flag = true;
            for(int i = 1;i < s.length();++i){
                if(base.find(tolower(s[i])) == string::npos){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(s);
        }
        return res;
    }
private:
    string base1 = "qwertyuiop";
    string base2 = "asdfghjkl";
    string base3 = "zxcvbnm";
};
```
