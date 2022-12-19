```
 public int trap(int[] height) {
        if(height.length==0) return 0;
        int len=height.length;
        int leftIndex=0;//从左遍历的下标
        int rightIndex=len-1;//从右遍历的下标
        int max=0;//最高的高度
        int countHeight=0;//能接的雨水数量
        int curMaxHeight=0;//当前最高点
        //遍历一遍寻找最高的高度
        for(int i=0;i<len;i++)
        {
            if(height[i]>max)
            {
                max=height[i];
            }
        }
        //从左到右遍历，直到最高点
        while(height[leftIndex]!=max)
        {
            curMaxHeight=height[leftIndex];
            while(height[leftIndex]<=curMaxHeight)
            {
                
                 countHeight+=curMaxHeight-height[leftIndex];
                 leftIndex++;
            }
            
        }
        //从右到左遍历，直到最高点
        while(height[rightIndex]!=max)
        {
            curMaxHeight=height[rightIndex];
            while(height[rightIndex]<=curMaxHeight)
            {
                
                 countHeight+=curMaxHeight-height[rightIndex];
                 rightIndex--;
            }
        }
        //计算从左边最高点到右边最高点能接到的雨水
        while(leftIndex!=rightIndex)
        {
            countHeight+=max-height[leftIndex];
            leftIndex++;
        }
        return countHeight;
    }
```
