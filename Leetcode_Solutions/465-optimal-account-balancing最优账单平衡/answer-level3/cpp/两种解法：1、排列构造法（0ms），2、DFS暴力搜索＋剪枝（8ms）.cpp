1、方法一
构造法确实牛，0ms完成，本解法参考了4ms纪录的答案
```cpp
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> note;
        vector<int> acc;
        for (auto& e : transactions) {
            note[e[0]] += e[2];
            note[e[1]] -= e[2];
        }
        for (auto& e : note) {
            if (e.second != 0) {
                acc.push_back(e.second);
            }
        }
        if (acc.empty()) {
            return 0;
        }
        sort(acc.begin(), acc.end(), greater<int>());
        int n = acc.size();
        int m = 0;
        int l = 2;
        int res = 0;
        vector<int> pos;
        function<bool(int, int)> helper = [n, &m, &l, &pos, &acc, &res, &helper](int start, int pstart)->bool{
            if (m == n) {
                return true;
            }
            bool found = false;
            for (int i = start; i < n && !found; i++) {
                if (acc[i] != 0) {
                    pos[pstart] = i;
                    if (pstart + 1 == l) {
                        int sum = 0;
                        for (int i = 0; i < l; i++) {
                            sum += acc[pos[i]];
                        }
                        if (sum == 0) {
                            res += l - 1;
                            for (int i = 0; i < l; i++) {
                                acc[pos[i]] = 0;
                                m++;
                            }
                            found = true;
                            break;
                        }
                    } else {
                        found = helper(i + 1, pstart + 1);
                    }
                }
            }
            return found;
        };
        while (m < n) {
            pos.resize(l);
            for (int i = 0; i <= n - l; i++) {
                if (acc[i] != 0) {
                    pos[0] = i;
                    helper(i + 1, 1);
                }
            }
            l++;
        }
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```

2、方法二
### 解题思路
把Lingo的解法剪枝优化可以达到8ms

### 代码

```cpp
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int res = INT_MAX;
        unordered_map<int, int> note;
        for (auto& e : transactions) {
            note[e[0]] += e[2];
            note[e[1]] -= e[2];
        }
        vector<int> acc;
        //acc.reserve(note.size());
        for (auto& e : note) {
            if (e.second != 0) {
                acc.push_back(e.second);
            }
        }
        if (acc.empty()) {
            return 0;
        }
        sort(acc.begin(), acc.end(), greater<int>());
        int n = acc.size();
        function<void(int, int)> helper = [n, &acc, &res, &helper](int start, int cnt) {
            if (cnt >= res) {
                return;
            }
            while (start < n && acc[start] == 0) {
                ++start;
            }
            if (start == n) {
                res = min(res, cnt);
                return;
            }
            for (int i = start + 1; i < n; ++i) {
                if ((acc[i] > 0 && acc[start] < 0) || (acc[i] < 0 && acc[start] > 0)) {
                    acc[i] += acc[start];
                    helper(start + 1, cnt + 1);
                    acc[i] -= acc[start];
                }
            }
        };
        helper(0, 0);
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```