### 解题思路
1. 因为只有字符，所以用一个int32位就可以记录。
2. 一次遍历，记录之前用的那个字符，到对应的位就可以了，O(N)

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int bit = 0;
        for (char c: astr) {
            int index = c - 'a';
            int newBit = 1<<index;
            if ((bit & newBit) == newBit) {
                return false;
            }
            bit |= newBit;
        }
        return true;
    }
};
```