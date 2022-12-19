### 解题思路
此处撰写解题思路

n & (n - 1) 可以把数的最后一个1消除

### 代码

```c
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
```