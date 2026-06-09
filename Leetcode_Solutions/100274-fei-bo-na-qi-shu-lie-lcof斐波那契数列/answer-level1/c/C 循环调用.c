执行用时 :4 ms, 在所有 C 提交中击败了60.48%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了100.00%的用户

```
int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long f1, f2, temp, value;
    long long modVal = 1e9 + 7;
    f1 = 1; f2 = 0;
    
    while (--n > 0) {
        value = f1 % modVal + f2 % modVal;
        temp = f1;
        f1 = value;
        f2 = temp;
    }
    
    return value % modVal;
}
```
