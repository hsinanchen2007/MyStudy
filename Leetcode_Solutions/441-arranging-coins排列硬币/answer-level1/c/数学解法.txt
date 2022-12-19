### 解题思路
数学法求解一元二次方程
(n)(n + 1)/2 = k

n^2 + n - 2k = 0;

(-1 + sqrt(1 + 8 K)/2);

### 代码

```c
int arrangeCoins(int n){
    return (int)((-1 + sqrt(1 + 8*(long)n))/2);
}
```