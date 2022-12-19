1.dp初始化说好不分手
2.转身，回眸
3.确认过眼神，我遇上对的人
```
class Solution {
public:
    static bool needRemove (char c) 
    {
        return !isalnum(c);
    }
    
    bool isPalindrome(string s) {
        vector<bool> dp;
        dp.push_back(true);
        
        string input = s;
        input.erase(remove_if(input.begin(), input.end(), needRemove), input.end());
        
        int i = input.size() / 2 - 1;
        int j = input.size() / 2 + input.size() % 2;
        for (; i >= 0 && j <= input.size() - 1; --i, ++j) {
            dp.push_back(dp.at(dp.size() - 1) && toupper(input.at(i)) == toupper(input.at(j)));
        }
        return *dp.rbegin();
    }
};
```
