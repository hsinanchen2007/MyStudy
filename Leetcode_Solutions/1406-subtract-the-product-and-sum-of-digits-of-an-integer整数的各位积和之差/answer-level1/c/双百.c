### 解题思路

基础题

### 代码

```c
int subtractProductAndSum(int n){
    int sum=0,product=1;
    while(n>0){
        int t=n%10;
        product*=t;
        sum+=t;
        n/=10;
    }
    return product-sum;
}   
```