### 思路一：暴力法

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 2 != 0) return false;
        while (n != 1) {
            if (n % 2 != 0) return false;
            n /= 2;            
        }
        return true;
    }
};
```

### 思路二：位运算
2的次方二进制中只有一个为1。

### 代码
```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    }
};
```

### 优化
2的次方数中二进制只有最高位为1，其余位都为0。所以可以只判断最高位是否为1。

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !((n - 1) & n);
    }
};
```


