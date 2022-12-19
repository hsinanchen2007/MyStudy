### 思路
1. 统计位置和字符完全相同数个数为 a 并将第一个字符串中数字出现次数建立哈希表。
2. 遍历猜数各个数字是否出现过，如果出现则递增 b 个数，同时将字符出现次数减 1 。
3. 从b中减去位置和字符完全相同数字个数a。

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        unordered_map<char, int> ump;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++a;
            ++ump[secret[i]];
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (ump[guess[i]] > 0) {
               ++b;
               --ump[guess[i]];
            } 
        }
        if (a > 0) b -= a;
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
```

### 优化
放在一个循环中，如果secret当前映射值小于0，则表示在guess中出现过，自增b，如果guess当前映射值大于0，则表示在secret中出现过，自增b。
```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0, m[256] = {0};        
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++a;
            else {
                if (m[secret[i]]++ < 0) ++b;
                if (m[guess[i]]-- > 0) ++b;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
```
