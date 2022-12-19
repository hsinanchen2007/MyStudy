### 解题思路
比正常排列多了一个判断（见注释），跳过重复项

### 代码

```cpp
class Solution {
public:
    vector<string> result;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return result;
    }
    void dfs(string& s, int pos) {
        if (pos >= s.size()) {
            result.push_back(s);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (judge(s, pos, i)) continue;   // 如果pos和i之间有字符等于s[i]，则跳过。
            swap(s[pos], s[i]);
            dfs(s, pos+1);
            swap(s[pos], s[i]);
        }
    }

    bool judge(string& s, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (s[i] == s[end]) return true;
        }
        return false;
    }
};
```