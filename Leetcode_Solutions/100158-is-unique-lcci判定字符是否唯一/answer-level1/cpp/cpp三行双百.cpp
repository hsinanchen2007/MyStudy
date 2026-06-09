### 解题思路

统计输出

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int sig[255]={0};
        for(auto &i:astr)if(sig[i]++)return false;
        return true;
    }
};
```