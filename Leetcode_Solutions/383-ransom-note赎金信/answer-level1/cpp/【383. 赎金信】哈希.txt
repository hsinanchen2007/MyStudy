### 思路

### 代码
时间复杂度：O()
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ump;
        for (auto c : magazine) {
            ++ump[c];
        }
        for (auto c : ransomNote) {
            if (ump[c] == 0) return false;
            --ump[c];
        }
        return true;
    }
};
```

### 优化
用数组模拟哈希表。
```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (auto c : magazine) {
            ++hash[c - 'a'];
        }
        for (auto c : ransomNote) {
            if (hash[c - 'a'] == 0) return false;
            --hash[c - 'a'];
        }
        return true;
    }
};
```


