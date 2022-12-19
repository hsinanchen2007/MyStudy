### 解题思路
1. 依次判断前一位与当前为是否不相同，若相同，则异或为`0`，返回`false`
2. 若每一位都符合，返回`true`

### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k = n & 1;
        for(int i = 1; i < 32; i++){
            if((1 << i) > n) break;
            int cur = (n >> i) & 1;
            if(cur ^ k  == 0) return false;
            k = cur;
        }
        return true;
    }
};
```