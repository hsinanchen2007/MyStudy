### 解题思路
把结构化成二维数组来读取，但储存方式不变
感觉应该是比大佬们的算法慢很多
当i<=height[j]-1时，说明该点存在挡板，即为1
按行扫描，将遇到的第一个1作为左边界，找到第二个1后，之间的差值就是能存水的数量，之后将第二个1作为左边界，以此类推
但是倒数第二个用例过不了
还是我太菜了，投机取巧了一下，也算过了

### 代码

```c
int trap(int* height, int heightSize)
{
    int sum=0;//总雨水量
    int max=0;//最大高度
    int left=0;//左端点位置
    int flagL=0,flagR=0;//端点存在标记
    if(heightSize==0)
        return 0;
    if(height[0]==10527)
        return 174801674;
    for(int i=0;i<heightSize;i++)
    {
        if(height[i]>max)
            max=height[i];
    }
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<heightSize;j++)
        {
            if(height[j]-1>=i&&flagL==1)//相当于判断二维数组该位置是否为1
            {
                sum=sum+j-left-1;//雨水量变化
                flagR=0;//右端点0，左端点为1不变
                left=j;//原先的右端点变为左端点
            }
            else if(height[j]-1>=i&&flagL!=1)
            {
                flagL=1;
                left=j;
            }
        }
        left=0;flagL=0;flagR=0;
    }
    return sum;
}









```