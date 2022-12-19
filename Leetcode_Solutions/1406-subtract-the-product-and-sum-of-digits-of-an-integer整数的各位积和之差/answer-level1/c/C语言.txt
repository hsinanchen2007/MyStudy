### 解题思路
此处撰写解题思路

### 代码

```c
int subtractProductAndSum(int n){
int sum=0,count=1,k;
while(n){
    k=n%10;
    n=n/10;
    count=count*k;
    sum=sum+k;
}
return count-sum;
}
```