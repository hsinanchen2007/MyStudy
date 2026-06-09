### 解题思路
`used`记录哪些数字被使用了
`weights`计算每个字母的权重
`notZero`记录哪些字母不能对应到0
`chars`记录所有用到的字母
然后回溯法求解

### 代码

```cpp
class Solution {
public:
    vector<int> used;
    vector<int> weights;
    vector<int> notZero;
    vector<int> chars;
    int N;
    Solution() {
        used = vector<int>(10, 0);
        weights = vector<int>(26, 0);
        notZero = vector<int>(26, 0);
        N = 0;
    }
    bool dfs(int i, int sum) {
        if (i == N) return sum == 0;
        for (int j = 0; j < 10; ++j) {
            if (notZero[i] && j == 0) continue;
            if (used[j]) continue;
            used[j] = true;
            if (dfs(i + 1, sum + j * weights[chars[i]])) return true;
            used[j] = false;
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        for (auto& w : words) {
            int p = 1;
            for (int i = w.size() - 1; i >= 0; --i) {
                chars.push_back(w[i] - 'A');
                weights[w[i] - 'A'] += p;
                p *= 10;
            }
            if (w.size() > 1) notZero[w[0] - 'A'] = 1;
        }
        int p = 1;
        for (int i = result.size() - 1; i >= 0; --i) {
            chars.push_back(result[i] - 'A');
            weights[result[i] - 'A'] -= p;
            p *= 10;
        }
        if (result.size() > 0) notZero[result[0] - 'A'] = 1;
        sort(chars.begin(), chars.end());
        chars.erase(unique(chars.begin(), chars.end()), chars.end());
        N = chars.size();
        int sum = 0;
        return dfs(0, sum);
    }
};
```

![image.png](https://pic.leetcode-cn.com/27abcb9088dd486bd30341e0300f5890add23044a0b27eaf35c971d92d076c0b-image.png)
