### 思路：find函数

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int size = astr.size();
        for (int i = 0; i < size - 1; ++i) {
            if (find(astr.begin() + (i + 1), astr.end(), astr[i]) != astr.end()) return false;
        }
        return true;
    }
};
```