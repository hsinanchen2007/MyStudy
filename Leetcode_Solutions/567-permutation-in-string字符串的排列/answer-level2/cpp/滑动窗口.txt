### 解题思路
因为要求是子串，所以只需要考虑长度等于`s1.size()`的子串，采用一个滑动窗口来统计每个字母出现的次数即可。

### 代码

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2)
            return false;
        vector<int> a(26), b(26);
        for (char c : s1)
            a[c - 'a']++;
        for (int i = 0; i < l2; ++i) {
            b[s2[i] - 'a']++;
            if (i >= l1)
                b[s2[i - l1] - 'a']--;
            if (i >= l1 - 1) {
                bool ok = true;
                for (int j = 0; j < 26; ++j)
                    if (b[j] != a[j]) {
                        ok = false;
                        break;
                    }
                if (ok)
                    return true;
            }
        }
        return false;
    }
};
```