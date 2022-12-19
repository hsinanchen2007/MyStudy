1. **使用`bitset`**   8 ms

count() 函数返回1的个数
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> b(n);
        return b.count();
    }
};
```
2. **使用神奇的函数`__builtin_popcount`**   8 ms

GCC有一个叫做__builtin_popcount的内建函数，它可以精确的计算1的个数
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
```

3. **二进制骚操作**   4 ms

参考李博杰的《骗分导论》

一波操作猛如虎，其实我也没看懂
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n=(n&0x55555555)+(n>>1&0x55555555);
        n=(n&0x33333333)+(n>>2&0x33333333);
        n=(n&0x0F0F0F0F)+(n>>4&0x0F0F0F0F);
        n=(n&0x00FF00FF)+(n>>8&0x00FF00FF);
        n=(n&0x0000FFFF)+(n>>16&0x0000FFFF);
        return n;
    }
};
```

