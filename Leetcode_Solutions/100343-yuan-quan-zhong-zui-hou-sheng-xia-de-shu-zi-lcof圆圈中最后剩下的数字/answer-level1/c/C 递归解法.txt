### 解题思路
上代码

### 代码

```c
int func(int n, int m) {
    if (n <= 1) {
        return 0;
    } else {
        return (m + func(n - 1, m)) % n; 
    }
}

int lastRemaining(int n, int m){
    return func(n, m);
}
```