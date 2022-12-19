### 解题思路
1，字符串从长到短逐渐考察是否满足条件
2，只要当前字符串没有与之相同的其他字符串，且也不是任何比它长的字符串的子序列，则满足条件

### 代码

```cpp
class Solution {
public:
    bool valid(unordered_set<string>& v, vector<string>& q) {
        sort(q.begin(), q.end());
        int i = 0;
        for (int j = 0; j < q.size(); ++j) {
            if (j > 0 && q[j] == q[j - 1]) continue;
            if (j < q.size() - 1 && q[j] == q[j + 1]) continue;
            if (v.empty()) return true;
            auto& x = q[j];
            for (auto& y : v) {
                int i = 0;
                int j = 0;
                while (i < x.size() && j < y.size()) {
                    if (x[i] == y[j]) {
                        ++i;
                        ++j;
                    } else {
                        ++j;
                    }
                }
                if (i != x.size()) return true;
            }
        }
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        map<int, vector<string> > m;
        for (auto& w : strs) {
            m[w.size()].push_back(w);
        }
        unordered_set<string> v;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            if (valid(v, it->second)) return it->first;
            v.insert(it->second.begin(), it->second.end());
        }
        return -1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/84070a772550dc16ee24c3c558981ae5ae2f6fbdc08c71588a984e60695c7b6f-image.png)
