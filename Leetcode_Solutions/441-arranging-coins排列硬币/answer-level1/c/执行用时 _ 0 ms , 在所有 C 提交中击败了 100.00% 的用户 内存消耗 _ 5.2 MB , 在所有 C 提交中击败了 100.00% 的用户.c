### 解题思路

数列求和公式, 调整了一下循环的起始点
注意精度问题

### 代码

```c
int arrangeCoins(int n){
    if (n == 0 || n == 1){
        return n;
    }
    int i = (int)(sqrt(n) * sqrt(2)) - 1;
    while(i < n){
        if( (double)i / 2. * (double)(i + 1) > (double)n ){
            break;
        }
        ++ i;
    }
    return i - 1;
}
```