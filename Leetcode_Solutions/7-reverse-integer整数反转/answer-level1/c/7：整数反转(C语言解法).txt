```
int reverse(int x)
{
    double ret = 0;
    while (x != 0) {
        ret = ret * 10 + x % 10;
        if ((int)ret != ret) {  // 溢出判断
            return 0;
        }
        x /= 10;
    }
    return (int)ret;
}
```
