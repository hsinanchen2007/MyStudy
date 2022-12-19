### 解题思路
遍历原数据，利用移位重新构造新的数据

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;    
    int i = 0;

    if(n == 0)
        return 0;

    for(i = 0; i < 32; i++) //构造新的数据
    {
        if(n&1)
        {
            result = (result<<1)|1;
        }
        else
        {
            result = (result<<1);
        }
        n = (n>>1);
    }

    return result;
}
```