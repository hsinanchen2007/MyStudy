### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n &= (n-1);
            res++;
        }
        return res;
    }
};
```