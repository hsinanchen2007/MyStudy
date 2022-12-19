### 解题思路
字符串最小长度 * 字符串个数
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int minLen = INT_MAX;
        for_each(strs.begin(), strs.end(), [&minLen] (const string& str) ->void {minLen = (minLen < str.size())?minLen:str.size();});
        if (minLen == 0 || minLen == INT_MAX) {
            return "";
        }
        int k = 0;
        while (k <= minLen) {
            int flag = 0;
            set<char> s;
            for (int i = 0; i < strs.size(); i++) {
                s.insert(strs[i][k]);
                if (s.size() > 1) {
                    flag = 1;
                    break;
                }
            }        
            if (flag == 1) {
                break;
            } else {
                k++;
            }
        }
        return strs[0].substr(0, k);
    }
};
```