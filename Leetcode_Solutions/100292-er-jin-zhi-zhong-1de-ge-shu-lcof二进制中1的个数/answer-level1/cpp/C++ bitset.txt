### 解题思路
借助bitset的话，一行。。
或者使用 n = n & (n-1) 这个算法可以去除掉n的最后一位1，然后循环统计1的个数。

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return (bitset<200> (n)).count();
    }
};
```

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0) {
            n = n & (n -1);
            res++;
        }
        return res;
    }
};
```