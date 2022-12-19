# 平均12ms，内存9MB多，有待优化。
# 想了好几个小时终于做出来了，留个纪念。。。
# 至于用得什么方法咱也说不清楚，可能有专业的说法，但咱也不知道。
主要就是慢指针不动，快指针去找比慢指针大的值，找到了就递归，让慢指针指向快指针现在的位置，然后快指针继续找更大的。之间每一步计算一次面积，比max大就赋值给max，其它一些细节
就很难说了，写得不多看懂还是容易的。
```
int largest(int* heights,int low,int high,int min,int *max)
{
    int max0=0,min0=heights[low];
    for(int i=low;i<=high;i++)
    {
        if(i==high||heights[i]<=min)
        {
            return i;
        }
        
        if(heights[i]>min0)
        {
            i=largest(heights,i,high,min0,max);
            i--;
            max0=(i-low+1)*min0;
            if(max0>*max)
                *max=max0;
        }
        else
        {
            min0=heights[i];
            max0=(i-low+1)*min0;
            if(max0>*max)
                *max=max0;
        }
    }
    return 0;
}

int largestRectangleArea(int* heights, int heightsSize){
    int max=0;
    if(heightsSize<=0)
        return max;
    
    largest(heights,0,heightsSize,-1,&max);
    return max;
}


```
