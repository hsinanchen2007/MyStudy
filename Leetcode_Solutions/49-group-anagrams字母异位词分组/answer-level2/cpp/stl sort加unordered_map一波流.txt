### 解题思路
本质上就是排序字符串中的字符然后用hash表记录，代码很简单，直接看就行

执行36ms，超过98.55%
内存17mb，超过96.53%

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> stringMap;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            auto itor = stringMap.find(tmp);
            int index;
            if (itor == stringMap.end())
            {
                res.push_back({});
                index = res.size() - 1;
                stringMap[tmp] = index;
            }
            else
            {
                index = itor->second;
            }
            res[index].push_back(strs[i]);
        }
        return res;
    }
};
```