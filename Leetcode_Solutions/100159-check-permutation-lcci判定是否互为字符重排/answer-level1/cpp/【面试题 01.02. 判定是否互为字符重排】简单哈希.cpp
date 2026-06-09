## 思路：哈希

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        vector<int> hash(256, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++hash[s1[i]];
            --hash[s2[i]];
        }
        for (int i = 0; i < hash.size(); ++i) {
            if (hash[i] != 0) return false;
        }
        return true;
    }
};
```