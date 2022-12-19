### 解题思路
题目说明一次只能跨一阶或两阶，那么要到达第n阶，要么在n-1阶跨1步，要么在n-2阶跨2步，于是我们得到以下公式：
methods[n] = methods[n-1]+methods[n-2];
由此便可得到如下代码
### 代码

```c
int climbStairs(int n){
    int methods[n+1];
    int i;
    methods[1] = 1;
    if(n >= 2)
        methods[2] = 2;
    for(i = 3;i <= n;i++){
        methods[i] = methods[i-1]+methods[i-2];
    }
    return methods[n];
}
```