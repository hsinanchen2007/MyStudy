### 解题思路
整型变量里面 4 的幂有 16 个，那就打个表吧

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        set<int> fourpow = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
        if(fourpow.find(num) == fourpow.end()){
            return false;
        }
        return true;
    }
};
```