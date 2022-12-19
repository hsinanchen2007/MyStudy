
### 代码

```c
// 法一：模方法
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        if (n % 2 == 1) count++;
        n /= 2;
    }
    return count;
}

// 法二：位操作运算
int hammingWeight(uint32_t n) {
    int count = 0;
    while ( n != 0) {
        // 将 n 的最右边的 1 置为 0
        n &= (n - 1);
        count++;
    }
    return count;
}

// 法三：位操作运算
int hammingWeight(uint32_t n) {
    int count = 0;
    while ( n != 0) {
        // 判断 n 的最低位是否为 0
        count += n & 0x01;
        n >>= 1;
    }
    return count;
}
```