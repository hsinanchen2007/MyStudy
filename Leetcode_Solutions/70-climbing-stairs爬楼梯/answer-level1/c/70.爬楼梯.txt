### 解题思路
利用%2不增加中间变量，用求和值替换小值，更新斐波那契数。

### 代码

```c
int climbStairs(int n){
    int a[2] = {1,2};
    int i;

    if(n == 1)
        return a[0];
    if(n == 2)
        return a[1];
    for( i = 3; i <= n; i++)
        a[(i+1)%2] = a[0] + a[1];
    //return climbStairs(n-1)+climbStairs(n-2);  //直接递归太消耗空间
    return a[i%2];
}
```