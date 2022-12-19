### 解题思路
    1、首先判断第一个高度不为0的柱子所在位置。
    2、以当前柱子的高度为基准，寻找更高的柱子。
    3、若找到更高的柱子，标注其位置，然后从后往前判断每个柱子的位置可装的雨滴数。即当i<j用height[i]-height[--j];
    4、找到更高的柱子后，以这个更高的柱子为当前柱子，重复2、3；
    5、若找不到更高的柱子，则降低当前柱子高度，再次寻找，直至找到更高的柱子或当前柱子高度为0。

### 代码

```c
int trap(int* height, int heightSize){
    int num=0;      //计算可装雨滴数量
    int i,j,k;      
    int dex=-1;     //
    for(k=0;k<heightSize;k++)
    {
        if(height[k]!=0)
        {
            break;
        }
    }
    for(i=k;i<heightSize;i++)
    {
        for(j=i+1;j<heightSize;j++)
        {
            if(height[i]<=height[j])
            {
                dex=j;
                while(i<j)
                {
                    num+=(height[i]-height[--j]);
                }
                break;
            }
        }
        if(i<dex)
        {
            i=dex-1;
        }
        else 
        {
            height[i]--;
            if(height[i]>0)
            {
                i--;
            }
        }
    }
    return num;
}
```