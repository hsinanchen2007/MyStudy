### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string check = "";
        for(int i = 0 ; i < 10 ; ++i)
        {   
            check += s[i];
        }
        mp[check]++;
        for(int i = 10 ; i < s.length() ; ++i)
        {
            check = check.substr(1);
            check = check + s[i];
            if(mp[check] == 1)
                ans.push_back(check);
            mp[check]++;
        }
        return ans;
    }
};
```