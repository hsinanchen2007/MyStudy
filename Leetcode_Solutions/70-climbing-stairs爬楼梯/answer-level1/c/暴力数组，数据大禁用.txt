### 解题思路
此处撰写解题思路
可能有点投机取巧的嫌疑，但是这个运行速度是相当快的，只有加法运送，不过如果数据太大，千万不要用，内存可能会超的
### 代码

```c
int climbStairs(int n)
{
int num[100]={0};num[0]=1,num[1]=2;

int i;
if(n==0||n==0)
return 1;
else if(n==2)
return 2;
else
{
for(i=2;i<n;i++)
num[i]=num[i-1]+num[i-2];
return num[n-1];
}
}
```