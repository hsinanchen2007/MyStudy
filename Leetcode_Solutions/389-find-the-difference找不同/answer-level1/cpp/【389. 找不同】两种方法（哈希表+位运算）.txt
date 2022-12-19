### 思路一：哈希表

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26);
        for (auto c : s) {
            ++hash[c - 'a'];
        }
        for (auto c : t) {
            if (hash[c - 'a'] == 0) return c;
            --hash[c - 'a'];        
        }
        return 0;
    }
};
```

### 思路二：位运算

### 代码
```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (auto c : s) res ^= c;
        for (auto c : t) res ^= c;
        return res;
    }
};
```
