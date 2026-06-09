### 解题思路
1、C语言求模的结果与被除数一样的符号；
2、越界判断，根据题解中的提示，不需要判断result == INT_MAX / 10和 reseult == INT_MIN / 10的两种情形；
### 代码

```c
int reverse(int x){
    int result = 0;

    while(x) {
        if (result > INT_MAX / 10 || result < INT_MIN / 10) {
            return 0;
        }
       result = (result * 10) + (x % 10);
        x /= 10;
    };
    return result;
}
```