### 解题思路
快乐小白的遍历 找到最高值k
核心 最高值左边 递增 右边递减
在0到k  找当前最大值 判断height[i]是否大于当前最大值,若大于就变当前最大值,否则 累加差值;
在heightSize-1到k 找当前最大值 判断height[i]是否大于当前最大值;

### 代码

```c
int trap(int* height, int heightSize){
    int num,sum=0,max=0,k=0,i;
    for(i=0;i<heightSize;i++)
    {
        if(height[i]>max)
        {
            k=i;
            max=height[i];
        }
    }
    int nowmax=0;
    for(i=0;i<k;i++)
    {
        if(nowmax<height[i])
        {
            nowmax=height[i];
        }
        else//(nowmax>height[i])
        {
            sum=sum+nowmax-height[i];
        }
    }
    nowmax=0;
    for(i=heightSize-1;i>k;i--)
    {
        if(nowmax<height[i])
        {
            nowmax=height[i];
        }else
        {
            sum=sum+nowmax-height[i];
        }       
    }
    return sum;
}
```