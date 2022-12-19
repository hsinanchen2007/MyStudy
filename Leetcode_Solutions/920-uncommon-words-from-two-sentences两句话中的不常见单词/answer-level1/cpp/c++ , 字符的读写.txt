### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> dict;
        string str;
        istringstream ss(A);
        while (ss >> str) {
            dict[str] += 1;
        }
        istringstream s(B);
        while (s >> str) {
            dict[str] += 1;
        }
        vector<string> res;
        for (auto iter : dict) {
            if (iter.second == 1) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
};
```