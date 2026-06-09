### 解题思路
此处撰写解题思路
1、取余%比取并集&所耗费时间短

### 代码

```c
int hammingWeight(uint32_t n) {
    int results = 0;

    while(n != 0)
    {
        results += n % 2;
        n = n >> 1;
    }

    return results;
}
```