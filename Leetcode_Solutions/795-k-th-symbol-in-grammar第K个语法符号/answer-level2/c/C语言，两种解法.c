C语言，两种解法，都不需要用到N，成绩在0~4ms之间波动。其中第二种解码借用了参数N做递归，设置了一个不可能的值用于区分是测试代码调用还是递归调用。

解法1：任一bit的值会与其父bit的值相同（如果自身是父bit的第一个子bit）或相反值（如果自身是父bit的第二个子bit），按照这个规律往前找，直到找到首个bit，即“0”，在过程中根据是自身第一个子bit还是第二个子bit而决定是否取反。代码：
```
int kthGrammar(int N, unsigned int K) {
    int ret = 0;
    int k = K - 1;
    while (k > 0) {
        ret = (k & 0x1) ^ ret; // if k's lsb is '0', ret = ret; else ret = !ret;
        k = k >> 1;
    }
    return ret;
}
```



解法2：经过观察可以推导出：第x个bit与 第 x - 2^n个bit的值是相反的，其中n满足2^n < x < 2^(n+1)，这样就可以每次将第 x - 2^n个bit的值取反，一直到第1个bit，即“0”。代码：
```
int kthGrammar(int N, unsigned int K) {
    int k1 = (N < 32) ? K - 1 : K;
    if (k1 == 0) {
        return 0;
    }
    unsigned int msb = 0x1;
    unsigned int temp = k1 >> 1;
    while (temp) {
        temp = temp >> 1;
        msb = msb << 1;
    }
    // msb has only one bit == 1, K ^ msb will clear K's msb
    int ret = kthGrammar(32, k1 ^ msb);
    return !ret;
}
```

