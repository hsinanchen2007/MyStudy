### 解题思路
暴力拆解的核心思想就是遍历.
二分法就是在暴力拆解的基础上,利用二分法查找下一个i
### 代码
>方法一 -暴力拆解
```c
int mySqrt(int x)
{
    if(x == 1) return 1;
    int n = x / 2;
    long int i;
    for(i=0; i<n; i++)
    {
        if(i*i == x) break;
        if(i*i<x && (i+1)*(i+1)>x) break; 
    }
    return i;
}
```
>方法二 - 二分法
```c
int mySqrt(int x)
{
    if(x == 1) return 1;
    int left = 1, right = x/2; tmp = 0;
    while(left < right)
    {
        tmp = (left + right + 1) / 2;
        // 如果满足 tem 的平方等于x 
        if(tmp = x / tmp)
        {
            left = tmp;
            break;
        }
        else if(tmp * tmp < x)
        {
            left = tmp;
        }
        else
        {
            right = tmp-1;
        }
    }
    return left;
}
```
