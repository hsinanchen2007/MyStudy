



class Solution 
{
    public int minHeightShelves(int[][] books, int shelf_width) 
    {    
        int n=books.length;
        int dp[]=new int[n+1];//申请了N-1个内存空间；
        for(int k=0;k<n+1;k++)
        {
            dp[k]=1000000;//设大点，这是上限，就算答案超出上限按这个也只有这么大的最大值；
        }
          dp[0] = 0;
        
        for(int i = 0;i < n; ++i)
        {
            int width = 0;
            int height = 0;
            for(int j = i; j >= 0; --j)
            {
                width += books[j][0];
                height = height>books[j][1]?height:books[j][1];
                if(width <= shelf_width)
                {
                    dp[i+1] = dp[i+1]<dp[j]+height?dp[i+1]:dp[j]+height;
                }else//dp用于存放存第N本书的最小书架高度。
                {
                    break;/*这么理解：我已经知道了从1本到i-1本的最小高度，现在一本一本从后往前把书和第i本放在一层，并且每次放书都比较一下，记录下最小的书架高度，直到放不下了；*/
                }
             }
         }
         return dp[n];
    }
}