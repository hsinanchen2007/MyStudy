### 解题思路
如题

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        int ans=0;
        while(n) {
            if(n&1)
                ans++;
            if(ans>1)
                return false;
            n>>=1;
        }
        return true;
    }
};
```