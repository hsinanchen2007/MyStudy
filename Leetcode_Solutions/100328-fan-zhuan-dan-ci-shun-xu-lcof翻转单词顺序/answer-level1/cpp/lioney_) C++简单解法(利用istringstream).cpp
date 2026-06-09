```
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string res, tmp;
        while(getline(is, tmp, ' ')) {
            if(tmp.empty()) continue;
            res = res.empty() ? tmp : tmp + " " + res;
        }
        return res;
    }
};
```
