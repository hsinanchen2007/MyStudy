### 解题思路
一波骚操作。。。就是估计会溢出。

### 代码

```c
int sumNums(int n){
    char a[n][n+1];
    return sizeof(a) >> 1;      // n(n+!) / 2
}
```