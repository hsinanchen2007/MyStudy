```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() == 0)
            return result;
        // else if (strs.size() == 1)
        //     return strs[0];
        int len = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < len)
                len = strs[i].length();
        }
        int i, j;
        for (i = 0; i < len; i++) {
            for (j = 0 /* 1 */; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i])
                    return result;
                if (j == strs.size() - 1)
                    result.push_back(strs[0][i]);
            }
        }
        return result;
    }
};
```
