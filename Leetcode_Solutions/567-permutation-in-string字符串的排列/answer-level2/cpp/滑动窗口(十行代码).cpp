
## 滑动窗口

用哈希表记录窗口中各个字符出现次数的差值

- 正数表示还应该出现几次
- 0表示正好
- 负数表示多出现了几次


## 代码实现

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto &c: s1) mp[c]++; // 记录 出现次数的差值

        int l = 0, r = 0;
        while (r < s2.size()){
            char c = s2[r++];
            mp[c]--; // 入窗
            while (l < r && mp[c] < 0){ // 出窗
                mp[s2[l++]] ++;
            }
            if (r - l == s1.size()) return true;
        }
        return false;
    }
};
```

[从零开始学算法](https://muyids.github.io/simple-algorithm/)