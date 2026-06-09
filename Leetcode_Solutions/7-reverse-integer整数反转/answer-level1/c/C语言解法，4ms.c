### 解题思路

简单的题目，还是考验审题中对溢的处理。在循环中，一旦发现当前值溢出了，就直接返回0.

另外，我还看了下C的正负数的取余和触法操作

```c
123 / 10 = 12
123 % 10 = 3
-123 / 10 = -12
-123 % 10 = -3
-3 / 10  = 0
-3 % 10  = -3
```


### 代码

```c
int reverse(int x){
    long res = 0;
    long tmp = x;
    int flag = 0;
    if  ( tmp < 0 ) {
        flag = 1;
        tmp = -tmp;
    } 
    while ( tmp != 0){
        res = 10 *res + (tmp % 10);
        if ( res > INT_MAX) return 0;
        tmp = tmp / 10;
    }
    if (flag == 1) res = -res;
    return res;

}
```