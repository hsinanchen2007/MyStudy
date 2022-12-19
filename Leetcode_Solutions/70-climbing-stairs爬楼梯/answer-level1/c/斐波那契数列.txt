### 解题思路
斐波那契数列。
开始的思路是用dp(动态规划)写的，写着写着发现是斐波那契数列

### 代码

```c
//斐波那契数列
int climbStairs(int n){
    int a=1,b=1,temp=0;
    while(--n){
        temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}
```