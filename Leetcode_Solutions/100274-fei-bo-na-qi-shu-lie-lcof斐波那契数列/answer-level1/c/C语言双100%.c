### 解题思路
感谢前排提示

### 代码

```c
int fib(int n){
    long long int a=0,b=1,c;
    for(int i=0;i<n;i++)
    {
        c=a;
        a=b;
        b=(c+b)%1000000007;
    }
    return a;
        
}
```