### 解题思路
经典解法

### 代码

```c
int subtractProductAndSum(int n){
     int a=1,b=0;

    while(n!=0)
    {
        a*=n%10;
        b+=n%10;
        n/=10;
    }
    return a-b;
}
```