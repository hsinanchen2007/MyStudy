### 解题思路
判断个位用&1 并不断右移

### 代码

```c
int hammingWeight(uint32_t n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}
```