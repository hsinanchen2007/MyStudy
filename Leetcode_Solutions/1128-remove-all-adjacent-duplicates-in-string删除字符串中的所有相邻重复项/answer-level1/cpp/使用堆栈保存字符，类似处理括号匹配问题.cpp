```
class Solution {
public:
    string removeDuplicates(string S) {
        string stk;
        for(auto s:S)
        {
            if(!stk.empty() && stk.back() == s)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(s);
            }
        }
        return stk;
    }
};
```
