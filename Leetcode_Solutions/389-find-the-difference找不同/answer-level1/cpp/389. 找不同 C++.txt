### 解题思路
1.因为根据题目描述，相同字符会出现两次，只有而不同的字符只出现一次，因此累次异或两个字符串中的每一个字符，剩下的字符就是不同的字符。

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        char different_char = 0;
        for(int i = 0;i < s.length();i++){
            different_char ^= s[i];
        }

        for(int i = 0;i < t.length();i++){
            different_char ^= t[i];
        }

        return different_char;
    }
};
```