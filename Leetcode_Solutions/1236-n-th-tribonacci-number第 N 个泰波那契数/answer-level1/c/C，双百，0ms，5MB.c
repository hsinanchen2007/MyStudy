### 解题思路
一开始没看懂题，以为要求所有的和，一直出错，原来只要最后3项

### 代码

```c
int tribonacci(int n){
    if(n<2) return n;
    else if(2==n) return 1;
    int a=0,b=1,c=1,s;   
    for(int i=3;i<=n;i++){
        s=a+b+c;
        a=b;
        b=c;
        c=s;
    }
    return s;
}
```