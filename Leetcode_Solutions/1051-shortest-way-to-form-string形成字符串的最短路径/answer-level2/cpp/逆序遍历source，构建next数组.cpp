### 解题思路
对于source中的每一个位置，我们找到下一个任意字母的最小序号。
遍历target，每次next序号大于等于n时，说明需要一个额外的source串，计数+1。

### 代码

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.size();
        vector<vector<int>> nxt(n);
        string s = source + source;
        vector<int> curr(26, -1);
        for (int i = n * 2 - 1; i >= 0; --i) {
            if (i < n) 
                nxt[i] = vector<int>(curr);
            curr[s[i] - 'a'] = i;
        }
        int idx = n - 1;
        int ans = 0;
        for (char c : target) {
            int t = nxt[idx][c - 'a'];
            if (t == -1)
                return -1;
            if (t >= n) {
                ans++;
                t %= n;
            }
            idx = t;
        }
        return ans;
    }
};
```