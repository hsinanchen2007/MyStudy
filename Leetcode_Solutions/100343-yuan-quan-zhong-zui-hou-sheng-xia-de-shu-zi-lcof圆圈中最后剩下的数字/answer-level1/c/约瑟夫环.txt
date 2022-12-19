### 解题思路
此处撰写解题思路

### 代码

```c
int lastRemaining(int n, int m){
    int res = 0;
    for (int i = 2; i <= n; ++i) {
        res = (res + m) % i;
    }
    return res;
}
```