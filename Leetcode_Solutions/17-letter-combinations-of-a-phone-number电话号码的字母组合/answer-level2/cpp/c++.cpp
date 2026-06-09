```
class Solution {
    unordered_map<char,string> m{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> res;
        auto ss = letterCombinations(digits.substr(1));
        for(int i=0;i<m[digits[0]].size();++i){
            string tmp(1,m[digits[0]][i]);
            if(ss.empty()){
                res.push_back(tmp);
                continue;
            }
            for(auto &s:ss){
                res.push_back(tmp+s);
            }
        }
        return move(res);
    }
};
```
