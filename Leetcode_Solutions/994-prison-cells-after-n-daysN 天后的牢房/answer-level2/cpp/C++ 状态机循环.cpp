```
class Solution {
public:
    int state(const vector<int>& cells) {
        int s = 0;
        for (auto x : cells) {
            s <<= 1;
            s |= x;
        }
        return s;
    }
    void next(vector<int>& cells) {
        for (int i = 1; i < cells.size() - 1; ++i) {
            cells[i] |= (1 - ((cells[i - 1] & 1) ^ (cells[i + 1] & 1))) << 1;
        }
        cells[0] = 0;
        cells.back() = 0;
        for (int i = 1; i < cells.size() - 1; ++i) {
            cells[i] >>= 1;
        }
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, int> m;
        int s = state(cells);
        m[s] = 0;
        while (N > 0) {
            --N;
            next(cells);
            s = state(cells);
            if (m.count(s)) {
                break;
            } else {
                m[s] = m.size();
            }
        }
        int loop = m.size() - m[s];
        N %= loop;
        while (N > 0) {
            next(cells);
            --N;
        }
        return cells;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0905b9ca77389970900c5fda2766e9bb1a98e88e728064e199f0cbd953e54e34-image.png)
