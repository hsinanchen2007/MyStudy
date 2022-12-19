### 思路：哈希表
哈希表统计每个字符出现次数，如果是回文串的排列，则字符出现次数为奇数的个数不能大于1。

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> hash(256, 0);
        for (auto c : s) {
            ++hash[c];
        }
        int cnt = 0;
        for (int i = 0; i < hash.size(); ++i) {
            if (hash[i] % 2 == 1) ++cnt;
        }
        return cnt <= 1;
    }
};
```