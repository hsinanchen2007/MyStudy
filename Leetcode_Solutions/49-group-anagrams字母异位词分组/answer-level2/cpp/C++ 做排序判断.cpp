### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {      
        vector<vector<string>> res;
        map<string, int> m;
        int num = 0;

        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m.count(tmp) == 0) {
                m[tmp] = num;
                res.push_back(vector<string>(0));
                res[num].push_back(strs[i]);
                num++;
            } else {
                res[m[tmp]].push_back(strs[i]);
            }
        }
        
        return res;
    }
};
```