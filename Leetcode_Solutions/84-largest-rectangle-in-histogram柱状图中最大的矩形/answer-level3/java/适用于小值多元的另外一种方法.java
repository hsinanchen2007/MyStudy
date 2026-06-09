  先找出矩形的最大高度max，第一层循环表示从0到max的每一个高度所形成的线，所有高度小于这条线的矩形作为分割点，将所有矩形分割成不同的解，记录他们的大小，选择最大值。
![图片.jpg](https://pic.leetcode-cn.com/6c70021de136a9504bc9bf3f890a58eed2f1b03c05af2e1b2213940f9cbd0600-%E5%9B%BE%E7%89%87.jpg)


```
class Solution {
    public int largestRectangleArea(int[] heights) {
        int i=0;
        int ib=0;
        int ia=0;
        int j=heights.length-1;
        int max=0;
             int maxb=0;
        int maxc=0;
    
        for(int ij=0;ij<=j;ij++)
        if(heights[ij]>max)
        max=heights[ij];
   for(int iak=0;iak<=j;iak++)
   {    ia=heights[iak];
       for( ib=0;ib<j+1;ib++){     
            if(heights[ib]<ia){
                maxc=Math.max(maxc,maxb);
                maxb=0;
            }else
              maxb=maxb+ia;
   }
    maxc=Math.max(maxc,maxb);
      maxb=0;

   }
        return maxc;
    }
}
```








