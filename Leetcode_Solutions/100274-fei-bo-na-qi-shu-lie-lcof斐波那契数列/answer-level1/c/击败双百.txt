### 解题思路
递归会TLE， 直接用循环做

### 代码

```c
int fib(int n){
    if(n<2) return n;
    int a[3], i;
    a[0]=0, a[1]=1;
    for(i=2;i<=n;i++){
        a[2]=(a[0]+a[1])%1000000007;
        a[0]=a[1];
        a[1]=a[2];
    }
    return a[2];
}
```