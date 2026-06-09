## 思路


### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> hash(256);
        for (char c : s) {
            ++hash[c];
        }
        for (char c : s) {
            if (hash[c] == 1) return c;
        }
        return ' ';
    }
};
```