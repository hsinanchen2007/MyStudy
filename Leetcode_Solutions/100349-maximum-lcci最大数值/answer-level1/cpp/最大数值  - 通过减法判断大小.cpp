### 解题思路
1. 两数相减，然后通过移位取得其符号位
2. 通过位运算得出结果

### 代码

```cpp
class Solution {
public:
    int maximum(int a, int b) {
        int k = ((long(a) - long(b)) >> 63) & 1;
        //若k为1，则k^1为0，结果为b；若k为0，则k^1为1，结果为a
        return b * k + a * (k ^ 1);
    }
};
```