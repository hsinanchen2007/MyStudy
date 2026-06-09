### 解题思路
对于输入：N = 10000000000, M = 10011, i = 2, j = 6，
mask=(1<<j-i+1)-1<<i
mask：0..00001111100;取反之后是1..11110000011；
N与取反的掩膜相与可以让j到i置0.
之后再与移位后的M按位或即可
![image.png](https://pic.leetcode-cn.com/3088e5829eb9407129b29bd7d39d0568f330f00535669f5c08b0f0c3ede3ceb0-image.png)

### 代码

```cpp
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int mask=(1<<j-i+1)-1<<i; 
        return (N&~mask)|M<<i;

    }
};
```