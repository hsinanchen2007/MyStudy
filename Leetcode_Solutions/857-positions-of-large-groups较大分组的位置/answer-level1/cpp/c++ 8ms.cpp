### 解题思路
一次遍历同时记录每个分组的左右索引及字符数

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int l, r;
        int cnt = 1;
        int len = S.length();
        vector<vector<int>> res;
        if (len < 3) {
            return res;
        }

        for (int i = 0; i < len; i++) {
            if (cnt == 1) {
                l = i;
            }
            if (i < len - 1 && S[i] == S[i + 1]) {
                cnt++;
            } else {
                r = i;
                if (cnt >= 3) {
                    res.push_back({l, r});
                }
                cnt = 1;
            }
        }
        return res;
    }
};
```

后来发现可以更简洁：
```
class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string S) {
            int l = 0, r = 0;
            int len = S.length();
            vector<vector<int>> res;

            while (r < len) {
                if (S[r] == S[r + 1]) {
                    r++;
                } else {
                    if (r - l >= 2) {
                        res.push_back({l, r});
                    }
                    r++;
                    l = r;
                }
            }
            return res;
        }
};
```