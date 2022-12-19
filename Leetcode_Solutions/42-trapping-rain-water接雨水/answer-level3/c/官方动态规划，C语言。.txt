### 解题思路
此处撰写解题思路

### 代码

```c
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int trap(int* height,int heightSize)//动态规划，储存最高高度；
{
    if(heightSize==0)
    {
        return 0;
    }
    int result=0;
    int left_max[heightSize];
    int right_max[heightSize];
    int i;
    left_max[0]=height[0];
    right_max[heightSize-1]=height[heightSize-1];
    for(i=1;i<heightSize;i++)
    {
        left_max[i]=max(left_max[i-1],height[i]);
    }
    for(i=heightSize-2;i>=0;i--)
    {
        right_max[i]=max(right_max[i+1],height[i]);
    }
    for(i=0;i<heightSize-1;i++)
    {
        result+=min(right_max[i],left_max[i])-height[i];
    }
    return result;
}








```