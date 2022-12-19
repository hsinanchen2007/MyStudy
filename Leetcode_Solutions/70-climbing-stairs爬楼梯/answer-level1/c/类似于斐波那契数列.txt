### 解题思路


### 代码

```c
int climbStairs(int n)
{
    if(n < 3)     
        return n;
    int n1 = 1;             //n1 一层台阶上法   
    int n2 = 2;             //n2 两层台阶上法
    int cur = 0;
    for(int i = 3; i <= n; ++i)    //第三层台及其以上就用迭代进行，第n层 = (n-1) + (n-2)
    {
        cur = n1 + n2;
        n1 = n2;
        n2 = cur;               //如果怕超出int的最大范围，可以对其取余
    }
    return cur;

}
```