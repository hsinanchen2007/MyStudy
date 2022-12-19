### 思路一：循环

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num  && num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
    }
};
```

### 思路二：位运算
4的次方数一定是2的次方数，但2的次方数不一定是4的次方数，通过4的次方数二进制可以发现4的次方数二进制中1只出现在奇数位。因此可以通过于奇数位都是1，偶数为都是0的数（1010101010101010101010101010101）进行与运算，结果仍为原来数。

### 代码
```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};
```
