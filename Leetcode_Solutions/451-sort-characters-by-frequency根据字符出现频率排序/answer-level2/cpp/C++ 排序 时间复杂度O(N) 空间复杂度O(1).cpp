时间复杂度：O(N) // 排序的规模始终是256, 所以只考虑输出字符串的时间开销
空间复杂度：O(1) // times和chars容器大小是固定的 不受输入影响

```cpp
class Solution {
public:
    string frequencySort(string s) {
        vector<int> times(256, 0); // 充当哈希表使用，times[i]表示字符i的出现次数
        for (const auto &c : s) {
            times[c]++;
        }
        vector<unsigned char> chars(256);
        for (int i = 0; i < 256; i++)
            chars[i] = i;
        // 将所有ASCII码字符按照各自出现的次数排序
        sort(chars.begin(), chars.end(), [&times](const unsigned char lhs, const unsigned char rhs) {
            return times[lhs] > times[rhs];
        });
        auto dt = s.begin();
        // 依次输出结果
        for (auto it = chars.begin(); times[*it]; it++) {
            auto c = *it;
            auto t = times[c];
            while (t--) {
                *dt++ = c;
            }
        }
        return s;
    }
};
```