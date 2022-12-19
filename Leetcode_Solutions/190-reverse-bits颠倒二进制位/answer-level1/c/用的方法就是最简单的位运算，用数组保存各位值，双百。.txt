### 解题思路
此处撰写解题思路

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    int x = 0 , i = 0 ,a[32] ;
    for( i = 0 ;i < 32 ;i++)
    {
        a[i] = n % 2 ;
        n/= 2 ;
    }
    for( i = 0 ; i <32; i++)
    {
        x+= a[i]*pow(2,31-i) ;
    }
    return x ;
}
```