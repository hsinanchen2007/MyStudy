
```
class Solution {
public:
    vector<int> findPermutation(string s) {
        int len = s.size();
        vector<int> ret;
        for(int i = 1; i <= len + 1; ++i) ret.push_back(i);
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'I') continue;
            int start = i;
            while(s[i] == 'D' && i < s.size()) i++;
            reverse(ret.begin() + start, ret.begin() + i + 1);
            i--;
        }
        return ret;
    }
};
```