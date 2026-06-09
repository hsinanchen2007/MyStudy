```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if (!len)
            return {};
        vector<string> res;
        string cur;
        backtrack(digits,res,0,len,cur);
        return res;
    }
    map<char, string> mp = { {'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},
                         {'9',"wxyz"} };
    void backtrack(string digits, vector<string>& res, int index, int& len, string& cur) {
        if (index == len) {
            res.push_back(cur);
            return;
        }
        for (int i=0;i<mp[digits[index]].size();i++) {
            cur.push_back(mp[digits[index]][i]);
            backtrack(digits, res, index+1, len, cur);
            cur.pop_back();
        }
    }
};
```
