### 解题思路
解法同LeetCode242.字母异位词，counter计数即可
用char counter[128]数组表示简单哈希计数，记录每个字符出现的次数
如果出每个字符在s1,s2的出现次数不同，则不能重排

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int len = s1.size();
        char counter[128] = {0};
        for (int i = 0; i < len; i++) {
            counter[s1[i]]++;
            counter[s2[i]]--;
        }
        for (int i = 0; i < 128; i++) {
            if (counter[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
```