简单

### 代码

```c
int subtractProductAndSum(int n){
    int t[4],i,sum=0,mul=1;
    while(n!=0){
        t[i]=n%10;
        n=(n-t[i])/10;
        sum+=t[i];
        mul*=t[i];
    } 
    return mul-sum;
}
```