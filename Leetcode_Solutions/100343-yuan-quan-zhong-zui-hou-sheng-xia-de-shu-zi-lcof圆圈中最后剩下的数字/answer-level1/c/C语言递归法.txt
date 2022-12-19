### 解题思路
递归法
1. 条件判断是否大于1
2. 不满足条件返回0
3. 满足条件则依次递归取值后取模m%n（m + lastRemaining(n - 1, m)) % n

### 代码

```c
int lastRemaining(int n, int m){
    int res;
    if (n <= 1) {
        res = 0;
    } else {
        res = (m + lastRemaining(n - 1, m)) % n; 
    }
    return res;
}
```