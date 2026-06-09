### 解题思路
主要需要考虑到负数，我们可以把有符号的数转化成无符号的数，虽说转变成了无符号数，对于负数来说，在计算机中的数改变了，但是和负数在计算机中的表示没有变；

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
       unsigned int _n = n;
       int res = 0;
       while(n){
           res += n & 1;
           n >>= 1;
       } 
       return res;
    }
};
```