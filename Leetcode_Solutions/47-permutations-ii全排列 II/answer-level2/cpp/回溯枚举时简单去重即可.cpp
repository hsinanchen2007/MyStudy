### 解题思路
代码跟46题几乎一样，多了一个步骤就是在枚举当前层级的候选集时，加了一个去重，因为选择重复的数字，走出来是一条重复的路。

### 代码

```cpp
class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> res;
        bt(a, res, 0);
        return res;
    }
    void bt(vector<int>& a, vector<vector<int>>& res, int level) {
        if (level == a.size()) {
            res.push_back(a);
            return;
        }
        //枚举的时候去重，只用没有排过的
        unordered_set<int> uniq;
        for (int i = level; i < a.size(); ++i) {
            if (uniq.count(a[i])) {
                continue; //already used
            }
            swap(a[i], a[level]);
            bt(a, res, level+1);
            swap(a[i], a[level]);
            uniq.insert(a[i]);
        }
    }
};
```