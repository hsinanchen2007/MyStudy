### 解题思路
简单冒泡法，时间用的长，但内存占用少，希望能够得到前辈的指导。

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    float MedianNum;
    int Length,temp;
    Length=nums1Size+nums2Size;
    int num[Length];
    //构成新数组
    for (int i = 0; i < nums1Size; i++)
    {
        num[i]=nums1[i];
    }
    for (int i = 0; i < nums2Size; i++)
    {
        num[nums1Size + i] = nums2[i];
    }
    //冒泡法排序
    for (int i = 0; i < Length-1; i++)
    {
        for (int j = 0; j < Length-1-i; j++)
        {
            if (num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
            
        }
        
    }
    //结果计算
    if (Length % 2 == 0)
    {
        MedianNum=(num[Length/2-1]+num[Length/2 + 1 - 1])/2.0;
    }
    else if (Length % 2 == 1)
    {
         MedianNum=num[(Length+1)/2-1];
    }
    
    return MedianNum;
}
```