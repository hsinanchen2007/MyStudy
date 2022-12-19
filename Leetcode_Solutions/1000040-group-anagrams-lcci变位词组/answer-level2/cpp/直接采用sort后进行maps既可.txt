### 解题思路

### 代码

```cpp
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> maps;
        for (int i = 0; i < strs.size(); i++) {
            string strTmp = strs[i];
            sort(strTmp.begin(), strTmp.end());
            if (maps.find(strTmp) != maps.end()) {
                maps[strTmp].push_back(strs[i]);
            } else {
                vector<string> vec = {strs[i]};
                maps[strTmp] = vec;
            }
        }
        vector<vector<string>> result;
        for (pair<string, vector<string>> pair1 : maps) {
            result.push_back(pair1.second);
        }
        return result;
    }
};
```