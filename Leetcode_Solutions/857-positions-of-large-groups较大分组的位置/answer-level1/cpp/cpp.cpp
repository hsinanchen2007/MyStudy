### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if (S.empty()) {
            return vector<vector<int>> ();
        }
        vector<vector<int>> res;
        int first = 0;
        for (int i = 0; i < S.size(); ) {
            while (i < S.size() && S[i] == S[first]) {
                i += 1;
            }
            if (i - first >= 3) {
                res.push_back(vector<int>({first, i - 1}));
            }
            first = i;
        }
        return res;
    }
};
```