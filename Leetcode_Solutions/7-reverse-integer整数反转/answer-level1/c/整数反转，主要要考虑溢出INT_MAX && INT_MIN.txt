```
int reverse(int x)
{
    int tmpX = x;
    long rst = 0;
    int tmp;
    while (tmpX != 0) {
        tmp = tmpX % 10;
        if(rst != 0 || tmp == 0){
            rst = rst * 10 + tmp;
        } else {
            rst = tmp;
        }
        tmpX /= 10;
        if (rst > INT_MAX || rst < INT_MIN) {
            return 0;
        }
    }   
    return rst;
}
```

