### 解题思路
创建一个26长度的字母统计数组，把s1转换成一个字母统计表，那么就不用考虑排列组合的问题
后面处理采用滑窗，提升效率，暴力检索重复计算过多，效率太低。

### 代码

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        vector<int> calc(26); // S1的字母统计表
        for (auto c : s1) {
            calc[c - 'a']++;
        }
        int n = s2.size();
        vector<int> window(26, 0);  // S2的字母统计表
        if (n < m) {  // s1比s2长，直接返回false
            return false;
        }
        for (int i = 0; i < m; i++) {  // 初始化字母统计表
            window[s2[i] - 'a']++;
        }
        for (int i = 0; i <= n - m; i++) {
            if (i != 0) {  // 从第二个开始，更新字母统计表
                window[s2[i - 1] - 'a']--; // 出去的字母统计减1
                window[s2[i + m - 1 ] - 'a']++; // 新进滑窗的字母统计+1
            }
            if (window == calc) {
                return true;
            }
        }
    return false;
    }
};
```