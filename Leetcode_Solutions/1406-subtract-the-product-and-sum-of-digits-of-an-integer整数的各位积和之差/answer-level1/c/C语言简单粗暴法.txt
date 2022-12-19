### 解题思路
分而治之即可，注意`for`的限制条件。

### 代码

```c
int subtractProductAndSum(int n){
    int product=1,sum=0;
    for ( ; n!=0 ; n/=10)
    {
        product*=n%10;
        sum+=n%10;
    }
    return product-sum;
}
```