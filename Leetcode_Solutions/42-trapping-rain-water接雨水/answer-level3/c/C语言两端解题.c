### 解题思路
先找到最大值所在的下标,然后分别计算最大值左边和最大值右边的储存量，左边的向右方移动左墙，右边的将右墙向左边移动，最后将两边的水加起来

### 代码

```c
int trap(int* height, int heightSize){
    int all_water = 0,left_water = 0,right_water = 0;
    int temp = 0;
    //int tempmax = 0;
    int maxnum = 0;
    int num;
    if(heightSize <= 1) return 0;
    int i=0,j=0;
    for(i=0;i<heightSize;i++)
    {
        if(height[i]>tempmax)
        {
            //tempmax = height[i];
            maxnum = i;
        }
    }
    i=0;
    while(i<maxnum)
    {
        while(height[i]==0)i++;
        for(j=i+1;j<=maxnum;j++)
        {
            if(height[j]<height[i])
            {
                temp+=height[i]-height[j];
            }
            else
            {
                i=j;
                break;
            }
        }
        left_water+=temp;
        temp=0;
    }
    i=heightSize-1;
    while(i>maxnum)
    {
        while(height[i]==0) i--;
        for(j=i-1;j>=maxnum;j--)
        {
            if(height[j]<height[i])
            {
                temp+=height[i]-height[j];
            }
            else if(height[j]>=height[i])
            {
                i=j;
                break;
            }
        }
        right_water+=temp;
        temp=0;
    }
    all_water = left_water+right_water;
    return all_water;
}
```