### 解题思路
简单的循环就可以实现，已知从第三个数开始未知，用sum值保存第三个数，然后一直循环递推即可
### 代码

```c
int tribonacci(int n){
    int a0=0,a1=1,a2=1;
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    int i,sum=0;
    for(i=2;i<n;i++){
        sum=a0+a1+a2;
        a0=a1;
        a1=a2;
        a2=sum;
    }
    return sum;
}
```