### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了68.07%的用户

首先是想到用递归的方式解决，其次要设置结束的语句，因为不仅是n==0一种情况还有n<0.而且两种情况带来的sum值的改变是不一样的，
然后就是递归主体。但是这样写44就会溢出，所以设置了数组加以优化，因为测试最大64，所以设置了65就行。最后就是把有的没的变量去掉就好。
### 代码

```c
int climbStairs(int n)
{
    int Mark[65] = {0};
    return Sum(n,Mark);
}
int Sum(int n,int Mark[])
{
    int sum = 0;
    if (n == 0)
        return sum + 1;
    if (n < 0)
        return 0;
    if (Mark[n] != 0)
        sum = Mark[n];
    else
    {
        sum = Sum(n - 1,Mark) + Sum(n - 2,Mark);
        Mark[n] = sum;
    }
    return sum;
}
```