### 解题思路
将AB合并，使用stringstream实现空格split，map计数，再用迭代器遍历map输出计数为1的单词

### 代码

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream ss(A + " " + B);
        string str;
        vector<string> ret;
        unordered_map<string, int> map;
        while (ss >> str) map[str]++;
        for (unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++) {
            if (it->second == 1) ret.push_back(it->first);
        }
        return ret;
    }
};
```
执行用时 :4 ms, 在所有 cpp 提交中击败了90.85%的用户
内存消耗 :9 MB, 在所有 cpp 提交中击败了84.21%的用户
