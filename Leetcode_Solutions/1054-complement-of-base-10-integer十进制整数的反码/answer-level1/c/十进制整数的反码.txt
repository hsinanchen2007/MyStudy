**设n的二进制表示有cnt位，则（2 ^ cnt - n - 1）即为所求。**
```c
int bitwiseComplement(int n)
{
    if(n == 0)
        return 1;
    int t = n, cnt = 0;
    while(t > 0){
        t >>= 1;
        cnt++;
    }
    return (1 << cnt) - 1 - n;
}
```