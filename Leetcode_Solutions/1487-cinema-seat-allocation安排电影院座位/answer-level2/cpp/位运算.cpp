### 解题思路

1. 按行排序预留座位列表
2. 逐行处理有预留座位的的行

时间复杂度: $O(N·LOG(N))$

进一步优化:
将座位表排序改为用hash表维护，时间复杂度可以降为$O(N)$

### 代码

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), [](const auto &lhs, const auto &rhs) {
           return lhs[0] > rhs[0]; 
        });

        auto it = reservedSeats.begin();
        constexpr short sum = 1 << 10;
        constexpr short lo = 0b0000011110;
        constexpr short hi = 0b0111100000;
        constexpr short mi = 0b0001111000;

        int ret = n * 2; // 无预留的情况下 每行最多放两个家庭

        while (it != reservedSeats.end()) {
            unsigned w = 0; // 用w的低10个bit位表示是否对应位置是否有预留
            n = (*it)[0];
            while (it != reservedSeats.end() && (*it)[0] == n) {
                w |= 1 << ((*it)[1] - 1);
                it++;
            }
            int tmp = 0;
            if ((w & lo) == 0) {
                tmp++;
                w |= lo;
            }
            if ((w & hi) == 0) {
                tmp++;
                w |= hi;
            }
            if ((w & mi) == 0) {
                tmp++;
                w |= mi;
            }
            ret -= 2 - tmp;
        }
        return ret;
    }
};
```

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, short> mis;
        for (const auto s : reservedSeats) {
            auto x = s[0];
            auto y = s[1];
            auto it = mis.find(x);
            if (it != mis.end())
                it->second |= 1 << (y - 1);
            else
                mis[x] = 1 << (y - 1);
        }

        auto it = reservedSeats.begin();
        constexpr short sum = 1 << 10;
        constexpr short lo = 0b0000011110;
        constexpr short hi = 0b0111100000;
        constexpr short mi = 0b0001111000;

        int ret = (n - mis.size()) * 2;
        static vector<short> vec;
        if (vec.size() == 0) {
            vec.resize(sum);
            for (auto ww = 0; ww < sum; ww++) {
                auto w = ww;
                int tmp = 0;
                if ((w & lo) == 0) {
                    tmp++;
                    w |= lo;
                }
                if ((w & hi) == 0) {
                    tmp++;
                    w |= hi;
                }
                if ((w & mi) == 0) {
                    tmp++;
                    w |= mi;
                }
                vec[ww] = tmp;
            }
        }

        for (auto it = mis.begin(); it != mis.end(); it++) {
            ret += vec[it->second];
        }
        return ret;
    }
};
```