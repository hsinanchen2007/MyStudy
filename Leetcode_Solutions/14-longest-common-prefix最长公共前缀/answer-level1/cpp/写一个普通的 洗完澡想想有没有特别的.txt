```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string longest = "";
        for(int i = 0; i < strs[0].size(); ++i) {
            for(int j = 1; j < strs.size(); ++j) {
                if(strs[0][i] != strs[j][i]) {
                    return longest;
                }
            }
            longest = longest + strs[0][i];
        }
        return longest;
    }
};
```
![image.png](https://pic.leetcode-cn.com/00b80cef6cc9e549734b08dd1673b5f46ecc6f26775ffccb95b6ef91bd042f09-image.png)
