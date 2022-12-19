纯C
```
#define isOverLength 0

int reverse(int x){
    long lRet = 0;
    while(0 != x)
    {
        lRet = lRet * 10 + x % 10;
        x = x / 10;
    }

    if((int)lRet != lRet)
    {
        return isOverLength;
    }

    return (int)lRet;
}
```
