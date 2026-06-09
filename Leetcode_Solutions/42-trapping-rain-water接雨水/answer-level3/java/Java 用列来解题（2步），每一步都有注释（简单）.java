### 解题思路
看图片，从第0列开始，找到0列左边和0列右边最大的值
    （1）如果得到的两个最大值都大于当前第0列，则用最小的最大值减去当前0列的值，存入结果中
    （2）否则就继续循环

### 代码

```java
class Solution {
    public int trap(int[] height) {
       int result=0;//雨水
       for(int i=0;i<height.length;i++)
       {
           //l_max：当前i列左边最大的值
           int l_max=lmax(i,height);
           //r_max：当前i列右边最大的值
           int r_max=rmax(i,height);
           //如果两边都有大于它的数
           if(l_max>height[i]&&r_max>height[i])
           {
               //如果左边的最大值大于右边的最大值
               if(l_max>r_max)
               {
                   //结果加上（右边的最大值-当前列的值）
                   result=result+r_max-height[i];
               }
               else{//如果左边的最大值小于右边的最大值
                    //结果加上（左边的最大值-当前列的值）
                   result=result+l_max-height[i];
               }
           }
       }
        //返回结果
       return result;
    }
    //求当前列左边最大的数字
    public int lmax(int index,int[] height)
    {
        int lmax=height[0];//让最大值初始值是当前列
        for(int i=0;i<index;i++)
        {
            //如果有比他还大的
            if(lmax<height[i])
            {
                //替换他
                lmax=height[i];
            }
        }
        return lmax;
    }
    //当前列右边最大的数字
    public int rmax(int index,int[] height)
    {
        int rmax=height[index];//让最大值初始值是当前列
        for(int i=index;i<height.length;i++)
        {
            //如果有比他还大的
            if(rmax<height[i])
            {
                //替换他
                rmax=height[i];
            }
        }
        return rmax;
    }
}
```