### 解题思路
对于每个字符串，使用bitset对其出现的字符计数，如果重复，bitset置0
遍历每个字符串，以该字符串为首，开始拼接，并记录该次使用过字符的bitset
后续字符串自身的bitset 与 前一次回溯的bitset，判定是否有重复位，如果有，则跳过本次迭代，没有则加入该字符串的bitset位，比较加入后的bitset为1的个数与结果result的大小，更新result

### 代码

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int sz = arr.size();
        vector<unsigned long> v(sz);
        bitset<26> bs(0);
        for (int i = 0; i < sz; ++i) {
            bs.reset();
            for (auto c : arr[i]) {
                // 该字符串中有重复字符
                if (bs[c - 'a'] == 1) {
                    bs.reset();
                    break;
                }
                bs[c - 'a'] = 1;
            }
            v[i] = bs.to_ulong();
        }
        if (sz == 1) {
            bitset<26> b(v[0]);
            return b.count();
        }

        unsigned long res = 0;
        backtrace(v, arr, 0, sz - 1, 0, res);
        return res;
    }

    void backtrace(vector<unsigned long>& v, vector<string>& arr, int start, int end, unsigned long bits, unsigned long& res) {
        if (start > end) {
            return;
        }
        if (start != 0 && bits == 0) {
            return;
        }
        unsigned long tmp = 0;
        for (int i = start; i <= end; ++i) {
            tmp = bits & v[i];
            if (tmp == 0) {
                    bitset<26> bs(bits | v[i]);
                    res = max(bs.count(), res);
                    backtrace(v, arr, i + 1, end, bs.to_ulong(), res);
            }
        }
    }
};
```