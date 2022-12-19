### 解题思路
此处撰写解题思路

### 代码

```c
int fib(int n){
    if(n<2) return n;
    unsigned long ans=0, d1 = 0, d2 = 1;
    for(int i=2; i<=n; ++i){
        ans = (d1 + d2) % 1000000007;
        d1 = d2;
        d2 = ans;
    }
    return ans;
}
```