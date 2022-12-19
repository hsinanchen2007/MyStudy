### 解题思路
开个数组就完事了

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int stone[256] = {0};
        for(size_t i = 0; i < S.size(); i++)
        {
            stone[S[i]]++;
        }

        int ret = 0;
        for(size_t i = 0; i < J.size(); i++)
        {
            ret += stone[J[i]];
        }

        return ret;
    }
};
```