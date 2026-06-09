### 解题思路

有点时候，暴力反而是最高效的解法。

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int size = astr.length();
        for(int i = 0; i < size; i++) {
            for(int j = 1; j < size; j++) {
                if(astr[i] == astr[j] && i != j) {
                    return false;
                }
            }
        }

        return true;
    }
};
```