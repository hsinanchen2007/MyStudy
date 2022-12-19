### 解题思路
整数溢出判断

### 代码

```c
int reverse(int x){
    long long ret = 0;
    int num = 0;
    //printf("%d", INT_MAX);
    while(x){
        num = x % 10;
        ret = ret * 10 + num;
        x /= 10;
    }
    if(ret > INT_MAX || ret < INT_MIN)
        return 0;
    return ret;
}
```