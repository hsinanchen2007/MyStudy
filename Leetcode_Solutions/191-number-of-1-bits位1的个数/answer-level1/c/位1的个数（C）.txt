**让n的每一位与1按位与，统计结果为1的个数即可。**
```c
int hammingWeight(uint32_t n) {
    int cnt = 0;
    for(int i = 0; i < 32; i++){
        if(n & 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}
```