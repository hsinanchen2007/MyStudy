### 解题思路
执行用时 :
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
8.6 MB, 在所有 C++ 提交中击败了23.24%
的用户

### 代码

```cpp
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (int i = 0; i < queries.size(); i++) {
            string temp = queries[i];
            int index = 0;
            bool tag = true;
            for (int j = 0; j < temp.size(); j++) {
                if (index < pattern.size() && temp[j] == pattern[index]) {
                    index++;
                    continue;
                }
                if (temp[j] >= 'A' && temp[j] <= 'Z') {
                    tag = false;
                    break;
                }
            }
            if (tag && index == pattern.size()) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};
```