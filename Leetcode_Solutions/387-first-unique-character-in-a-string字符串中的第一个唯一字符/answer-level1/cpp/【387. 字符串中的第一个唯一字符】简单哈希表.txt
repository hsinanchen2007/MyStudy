## 思路
### 代码
```c++
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26, 0);
        for (char ch : s) {
            ++hash[ch - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (hash[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```
