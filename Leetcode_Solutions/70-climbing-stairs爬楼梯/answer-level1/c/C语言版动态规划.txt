递归也可以解出来，但会超时


执行用时 : 0 ms, 在Climbing Stairs的C提交中击败了100.00% 的用户

内存消耗 : 7.1 MB, 在Climbing Stairs的C提交中击败了5.20% 的用户
```c
int climbStairs(int n){
    if(n < 0)
        return -1;
    
    int *res = malloc(sizeof(int)* (n+1));
    res[0] = 1;
    res[1] = 2;
    for (size_t i = 2; i < n; i++)
    {
        res[i] = res[i-1] + res[i-2];
    }
    return res[n-1]; 
}
```

递归版本
```c
int climbStairs(int n)
{
    int result = 0;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    result = climbStairs(n-1) + climbStairs(n-2);
    return result;
}
```
