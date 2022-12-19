### 解题思路
此处撰写解题思路
斐波那契
### 代码

```c
int climbStairs(int n){
    int n1 = 1, n2 = 2, n3 = 0, i;
    if (n == 1) return 1;
    if (n == 2) return 2;
    for (i = 3; i <= n; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}
```