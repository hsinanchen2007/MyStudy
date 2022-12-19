### 解题思路
相同字符两两相消。对于每个字符，如果哈希表里没有这个字符则插入，否则删掉。最后哈希表如果剩下 0 个或者 1 个字符则可以变成回文串，否则不行。

### 使用 STL 的 unordered_set
```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> uset;
        for (char c: s) {
            auto res = uset.insert(c);
            if (!res.second) {
                uset.erase(res.first);
            }
        }
        return uset.size() <= 1;
    }
};
```

### ASCII 是有限的，可以用原生数组模拟一个哈希表
```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool table[128] = { false };
        int size = 0;
        for (char c: s) {
            if (table[c]) {
                table[c] = false;
                size--;
            } else {
                table[c] = true;
                size++;
            }
        }
        return size <= 1;
    }
};
```