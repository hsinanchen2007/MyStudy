基本思路：要确定存在三个连续的坑才能在中间插入。但是需要注意左右两边的边界问题和单元素的极端情况。
对于前者细致分为三种情况：
1.左边界，只需要考虑相邻右元素是否存在坑
2.右边界，只需要考虑相邻左元素是否存在坑
3.中间，考虑左右两边元素是否存在坑
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int count=0,i;//计数器
    if(flowerbedSize==1&&flowerbed[0]==0)
        count++;
    else
    {
         for(i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==0)
        {
            if(i==0)//首元素,处理左边界
            {
            if(flowerbed[1]==0)
                {
                count++;
                flowerbed[i]=1;
                }
            }
            else if(i==flowerbedSize-1)//处理右边界
            {
                if(flowerbed[i-1]==0)
                    count++;
                    flowerbed[i]=1;
            }
        else if(flowerbed[i-1]==0&&flowerbed[i+1]==0)//处理中间元素
        {
            count++;
            flowerbed[i]=1;
        }
        }
    } 
    }
        if(count>=n)
        return true;
        return false;
}