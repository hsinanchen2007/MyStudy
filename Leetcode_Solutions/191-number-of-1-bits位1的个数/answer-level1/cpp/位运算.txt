### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return n==0? 0:n&1? hammingWeight(n>>1)+1:hammingWeight(n>>1);
    }
};
```