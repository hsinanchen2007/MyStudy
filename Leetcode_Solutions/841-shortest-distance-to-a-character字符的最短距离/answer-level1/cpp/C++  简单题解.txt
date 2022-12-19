### 解题思路
一次遍历即可

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int L = -1;
        int R = -1;
        int N = S.size();
        vector<int> res(N, 0);
        for (int i = 0; i < N; ++i) {
            if (S[i] == C) {
                L = R;
                R = i;
                for (int j = L + 1; j < R; ++j) {
                    if (L == -1) {
                        res[j] = R - j;
                    } else {
                        res[j] = min(R - j, j - L);
                    }
                }
            }
        }
        for (int j = R + 1; j < N; ++j) {
            res[j] = j - R;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a99a181d3e9654cca6395d5c01ca718465b49c3e14498df5bbf8e5d0b0cebced-image.png)
