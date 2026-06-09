### 解题思路
此处撰写解题思路

### 代码

```c
//直接递归显然不行，这样很多数都被重复计算，运行超出时间限制

int climbStairs(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    
    //对n>2的数怎么办？
    int Num1=1;
    int Num2=2;
    int NumN=0;
    for(int i=3;i<=n;i++)   //类似斐波那契数列的思想：迭代法，不要盲目递归
    {
        NumN=Num1+Num2;
        Num1=Num2;
        Num2=NumN;
    }
    return NumN;
}
```