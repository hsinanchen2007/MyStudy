### 解题思路
记住小技巧

### 代码

```c
int hammingWeight(uint32_t n) 
{
    int cnt = 0;

    while (n) {
        n = n & (n - 1);
        cnt++;
    }    

    return cnt;
}
```