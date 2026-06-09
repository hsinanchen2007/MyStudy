### 解题思路
求多少种可能性问题，同斐波拉契数解题思路，只是改变了初始值。

### 代码

```c
int numWays(int n){
    int a=1,b=1,c;
    for(int i=0;i<n;i++)
    {
        c=a;
        a=b;
        b=(a+c)%1000000007;
    }
    return a;
}
```