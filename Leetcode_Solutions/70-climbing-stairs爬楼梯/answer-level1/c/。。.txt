### 解题思路
此处撰写解题思路

### 代码

```c
int climbStairs(int n)
{
    int i=3,res;
    int num1=1;
    int num2=2;
    if(1==n) return num1;
    else if(2==n) return num2;
    
    while(i<=n)//从3开始
    {
        res=num1+num2;//状态转移方程:F(x)=F(x-1)+F(x-2)
        num1=num2;
        num2=res;
        i++;
    }
    return res;
}
```