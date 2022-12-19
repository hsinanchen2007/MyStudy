### 解题思路
此处撰写解题思路
1、该题采用了动态规划的办法。因为一次只能走1步或者2步，所以An=An-1+An-2；

### 代码

```c
int climbStairs(int n){
    int a0, a1, a2;
    
    if (n == 1)
    {
        return 1;
    }

    if(n == 2)
    {
        return 2;
    }

    a0 = 1;
    a1 = 2;
    n -= 2;

    while(n)
    {
        a2 = a0 + a1;
        a0 = a1; 
        a1 = a2;
        n--;
    }

    return a2;
}
```